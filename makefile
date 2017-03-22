all: reads_merger.o fastq_to_fasta_converter.o main.o
	@echo "=== Compiling library..."
	@g++ -o fastq_files_converter reads_merger.o fastq_to_fasta_converter.o main.o
	@echo "=== Done."
	
main.o: main.cpp
	@echo "=== Compiling the main program..."
	@g++ -c main.cpp

reads_merger.o: reads_merger.hpp
	@echo "=== Compiling reads_merger..."
	@g++ -c reads_merger.cpp

fastq_to_fasta_converter.o: fastq_to_fasta_converter.hpp
	@echo "=== Compiling fastq_to_fasta_converter..."
	@g++ -c fastq_to_fasta_converter.cpp


DATA_FOLDER=./data

run: all
	./reads_merger ${DATA_FOLDER}/output ${DATA_FOLDER}/input_1 ${DATA_FOLDER}/input_2 ${DATA_FOLDER}/input_3 ${DATA_FOLDER}/input_4

clean:
	@echo "=== Cleaning files..."
	@rm -rf ./reads_merger *.o
	@echo "=== Done."
