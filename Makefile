OUTFILE="run.out"
compile:
	@g++ -I ./headers/ -o $(OUTFILE) code/*.cpp
