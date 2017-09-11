# FastqFilesConverter
Program allowing to perform the following transformations on fastq files:
- merge several fastq files in one interleaved fastq file
- convert files in fastq format to fasta format
- remove read pairs containing a specified DNA sequence from paired-end fastq files


# User's guide
The program can be launched by invoking launcher.exe.

## Mandatory parameters:
- **-x**: the program to execute
    - **merger**
    - **converter**
    -  **seq_remover**
- **-i**: the list of input files (in case of paired-end files, the order of files is file1_R1 file1_R2 file2_R1 file2_R2...)
- **-o**: the output file or directory

## Optional parameters:
- **-s**: DNA sequence to remove, in case of seq-remover program

## Sub-programs

### Merger

Merger takes as input a list of paired-end files in fastq format and provides a unique interleaved file in fastq format. The program launches an error if an uneven number of input files is provided.

```
launcher.exe -x merger -i i1_r1.fastq i1_r2.fastq i2_r1.fastq i2_r2.fastq -o ${DATA_DIR}/output_merger.fastq
```

### Converter

Converter takes as input one file in fastq format and converts it in fasta format.

```
launcher.exe -x converter -i output_merger.fastq -o output_converter.fasta
```

### Sequences remover

Sequences remover takes as input one or several pairs of paired-end fastq files and a DNA sequence. Of one (or both) read(s) of a read pair contain this sequence, the entire pair of reads is removed. The output files will be stored in the specified output_folder and will be named by taking the original file names and prefixing them with "filtered\_" prefix. An additional file, filtered_reads.fastq, will contain all the filtered sequences.

```
launcher.exe -x seq_remover -i i1_r1.fastq i1_r2.fastq -o output_folder
```
