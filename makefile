all: reads_merger.o main.o
	g++ -o reads_merger reads_merger.o main.o

main.o: main.cpp
	g++ -c main.cpp

reads_merger.o: reads_merger.hpp reads_merger.cpp
	g++ -c reads_merger.cpp

DATA_FOLDER=./data

run: all
	./reads_merger ${DATA_FOLDER}/output ${DATA_FOLDER}/input_1 ${DATA_FOLDER}/input_2 ${DATA_FOLDER}/input_3 ${DATA_FOLDER}/input_4

clean:
	rm ./reads_merger *.o
