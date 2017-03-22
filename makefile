DATA_FOLDER=./data
SOURCES_FOLDER=./src


all: main.o
	@echo "=== Compiling library..."
	@g++ -o fastq_files_converter reads_merger.o fastq_to_fasta_converter.o command_line_arguments.o main.o
	@echo "=== Done."
	
main.o: reads_merger.o fastq_to_fasta_converter.o command_line_arguments.o
	@echo "=== Compiling the main program..."
	@g++ -c ${SOURCES_FOLDER}/main.cpp

reads_merger.o: ${SOURCES_FOLDER}/reads_merger.hpp
	@echo "=== Compiling reads_merger..."
	@g++ -c ${SOURCES_FOLDER}/reads_merger.cpp

fastq_to_fasta_converter.o: ${SOURCES_FOLDER}/fastq_to_fasta_converter.hpp
	@echo "=== Compiling fastq_to_fasta_converter..."
	@g++ -c ${SOURCES_FOLDER}/fastq_to_fasta_converter.cpp
	
command_line_arguments.o: ${SOURCES_FOLDER}/command_line_arguments.hpp
	@echo "=== Compiling command_line_arguments..."
	@g++ -c ${SOURCES_FOLDER}/command_line_arguments.cpp


run: all
	./fastq_files_converter -j merger -o ${DATA_FOLDER}/output -i ${DATA_FOLDER}/input_1 ${DATA_FOLDER}/input_2 ${DATA_FOLDER}/input_3 ${DATA_FOLDER}/input_4

clean:
	@echo "=== Cleaning files..."
	@rm -rf ./reads_merger *.o
	@echo "=== Done."
