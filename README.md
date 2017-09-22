# FastqFilesHandler user's guide
Program allowing to perform the following transformations on fastq files:
- merge several fastq files in one interleaved fastq file
- convert files in fastq format to fasta format
- remove read pairs containing a specified DNA sequence from paired-end fastq files


# Compilation
The program can be compiled by running "make" command in the main folder.


# Usage
The program can be launched by invoking launcher.exe situated in bin folder.

## Mandatory parameters:
- **-x**: the program to execute
    - **merger**
    - **converter**
    -  **seq_remover**
- **-i**: the list of input files (in case of paired-end files, the order of files is file1_R1 file1_R2 file2_R1 file2_R2...)
- **-o**: the output file or directory

## Optional parameters:
- **-s**: DNA sequence to remove, in case of seq_remover program
- **-b**: begin index, in case of seq_remover program
- **-e**: end index, in case of seq_remover program

## Sub-programs

### Merger

Merger takes as input a list of paired-end files in fastq format and provides a unique interleaved file in fastq format. The program raises an error if an uneven number of input files is provided.

```
launcher.exe -x merger -i i1_r1.fastq i1_r2.fastq i2_r1.fastq i2_r2.fastq -o ${DATA_DIR}/output_merger.fastq
```

### Converter

Converter takes as input one file in fastq format and converts it in fasta format. The program raises an error if more than one input file is provided.

```
launcher.exe -x converter -i output_merger.fastq -o output_converter.fasta
```

### Sequences remover

Sequences remover takes as input one or several pairs of paired-end fastq files and one or several DNA sequences. If one (or both) read(s) of a read pair contain(s) one of these sequences, the entire pair of reads is removed. The output files are stored in the specified output_folder (wchich must be created by the user) and are named by taking the original file names and prefixing them with "filtered\_" prefix. An additional file, filtered_reads.fastq, contains all the filtered sequences.

If needed, a begin and/or end index can be specified in order to restring the search space on reads to the desired intervalle.

```
launcher.exe -x seq_remover -i i1_r1.fastq i1_r2.fastq -o output_folder -s AATGATACGGCGACCACCGAGAT TAGGCTTCA -b 10 -e 200
```
