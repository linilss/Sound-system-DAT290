
PDFLATEX_OPTS = -interaction=errorstopmode -file-line-error -halt-on-error -output-format pdf

.PHONY: all

# the files listed after all are the ones make will try to generate if you just type "make" without specifying a filename
# it will only re-generate the files if the source files have changed, which it checks by comparing the
# file creation/modification dates
all: projektplan.pdf

# how this works:
# these are the instructions to make for how to generate projektplan.pdf
# on the first line it is told what the source files are to generate this file
# (so it can determine if they have changed)
# the rest of the lines are commands that are run to generate the files
# if you want to add more documents to be auto-generated when make is typed just
# copy paste these lines and change the filenames
# also add the new file to the "all: " line above
# if you have questions or something breaks ask Andreas
projektplan.pdf: projektplan.tex referenser.bib
	pdflatex $(PDFLATEX_OPTS) projektplan.tex
	bibtex projektplan
	pdflatex $(PDFLATEX_OPTS) projektplan.tex
	pdflatex $(PDFLATEX_OPTS) projektplan.tex
	rm -f projektplan.aux projektplan.log projektplan.bbl projektplan.blg
