// compile this file with: gcc -lm -lao -o digital-filter-test digital-filter-test.c
// uncomment the filter you want to test in the loop in the main function

#include <stdio.h>
#include <ao/ao.h>
#include <math.h>

#define SAMPLE_RATE 48000
#define VOLUME 0.25
#define BUFFER_SIZE 4096

// how long to delay (number of samples)
#define ECHO_TIME 24000
// power reduction of echo (decibel)
#define ECHO_VOLUME 6

float decibel_to_amplitude_ratio (float dB) {
    return 10 * powf(10.0, dB / 20.0);
}

float calc_amplitude_ratio_ceiling() {
    float echo_amplitude = decibel_to_amplitude_ratio(ECHO_VOLUME);

    // the exact value is the sum as i goes to infinity, but going to 100 is a good enough approximation
    float sum = 0;
    for (int i=0; i<=100; i++) {
        sum += 1.0/powf(echo_amplitude, i);
    }

    return sum;
}

ao_device *da_init() {

	ao_sample_format format;
	format.bits = 16;
	format.channels = 1;
	format.rate = SAMPLE_RATE;
	format.byte_format = AO_FMT_LITTLE;

	ao_initialize();
	ao_device *device = ao_open_live(ao_default_driver_id(), &format, NULL);
	return device;
}

// simulate DA by collecting samples in buffer and sending to sound card
void da_play_sample(ao_device *device, float sample) {
	static char sample_buffer[BUFFER_SIZE*2] = {0};
	static int sample_index = 0;

	// convert from float to integer, clipping if needed
	if (sample < -1.0) sample = -1.0;
	else if (sample > 1.0) sample = 1.0;
	sample_buffer[sample_index*2] = ((int) (sample * 32768.0)) & 0xff;
	sample_buffer[sample_index*2+1] = ( ((int) (sample * 32768.0)) >> 8) & 0xff;

	// output samples
	sample_index = (sample_index + 1) % BUFFER_SIZE;
	if (sample_index == 0) ao_play(device, sample_buffer, BUFFER_SIZE*2);
}

// simulate AD with a very basic tone generator
float ad_get_sample() {
	float freqs[] = { // note count: 52
		261.63, 261.63, 392.0, 392.0, 440.0, 440.0, 392.0, 0.0, 349.23, 349.23, 329.63, 329.63, 293.66, 293.66, 261.63, 0.0,
		392.0, 392.0, 349.23, 349.23, 329.63, 329.63, 293.66, 0.0,
		392.0, 392.0, 349.23, 349.23, 329.63, 329.63, 293.66, 0.0,
		261.63, 261.63, 392.0, 392.0, 440.0, 440.0, 392.0, 0.0, 349.23, 349.23, 329.63, 329.63, 293.66, 293.66, 261.63, 0.0,
		0.0, 0.0, 0.0, 0.0,
	};

	static unsigned long sample_id = 0;
	float sample;
	if (sample_id % SAMPLE_RATE < (SAMPLE_RATE * 7/8)) {
		float freq = freqs[sample_id / SAMPLE_RATE];
		sample = VOLUME * sin(2 * M_PI * freq * ( (float) (sample_id % SAMPLE_RATE) / SAMPLE_RATE) );
	}
	else {
		sample = 0;
	}
	sample_id = (sample_id + 1) % (SAMPLE_RATE * 50);
	return sample;
}

// simple two-band equalizer filter
float filter_equ(float sample) {
	static float current_freq = 0;
	static float last_sample = 0;
	static float count = 0;

	// estimate current frequency
	count++;
	if ( (sample >= 0 && last_sample < 0) || (sample < 0 && last_sample >= 0)) {
		current_freq = ( (float) SAMPLE_RATE) / ((float) count * 2.0);
		count = 0;
		//printf("freq %f\n", current_freq);
	}
	last_sample = sample;

	// increase volume by 6dB if frequency is less than 330, otherwise lower it by 6dB
	if (current_freq < 340.0) {
		sample = sample * 2;
	} else {
		sample = sample / 2;
	}
	return sample;
}

// simple echo filter
float filter_echo(float sample) {
	static float buffer[ECHO_TIME] = {0};
	static unsigned long sample_id = 0;

	float new_sample = sample + buffer[sample_id];
	buffer[sample_id] = sample * 0.5;
	sample_id = (sample_id + 1) % (ECHO_TIME);

	return new_sample;
}

int main(void) {
	ao_device *device = da_init();
	float sample_buffer[BUFFER_SIZE];
	int buffer_index = 0;

	while (1) {
		float sample = ad_get_sample();
		//sample = filter_echo(sample);
		sample = filter_equ(sample);
		da_play_sample(device, sample);
	}

	ao_close(device);
	ao_shutdown();
	return (0);
}
