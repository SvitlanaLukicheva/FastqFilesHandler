INPUT_DIR=/cygdrive/d/genome_assembly/input/illumina/250bp/trimmed
OUTPUT_DIR=/cygdrive/c/Users/svitl/Desktop/illumina_filtered_trimmed
PROGRAM=./bin/launcher
SEQUENCE=AGTATGGCCCGGGGGATCCTACGTT

${PROGRAM} -x seq_remover -i ${INPUT_DIR}/*R1* ${INPUT_DIR}/*R2* -o ${OUTPUT_DIR} -s ${SEQUENCE}
