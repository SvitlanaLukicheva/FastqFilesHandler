############ PERSONAL NOTES ############

# this makefile is inspired from https://stackoverflow.com/a/27794283/8592608


############ VARIABLES DEFINITIONS ############

# compiler
CC := g++


# project related global variables
TARGET     := launcher
DATA_DIR   := data
SRC_DIR    := src
BUILD_DIR  := obj
TARGET_DIR := bin
SRC_EXT    := cpp
OBJ_EXT    := o

# compiler related variables
SOURCES    := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
OBJECTS    := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.$(OBJ_EXT)))



############ COMPILER COMMANDS ############

# default make
all: directories $(TARGET)
	@echo "=== Done."

# remake
remake: full_clean all

# create the directories
directories:
	@echo "=== Creating directories..."
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(TARGET_DIR)

# target creation	
$(TARGET): $(OBJECTS)
	@echo "=== Building final file..."
	@$(CC) -o $(TARGET_DIR)/$(TARGET) $^
	
# compilation
$(BUILD_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(dir $@)
	@echo "=== Compiling $@..."
	@$(CC) -c -o $@ $<

# clean only objects
clean:
	@echo "=== Cleaning objects..."
	@$(RM) -rf $(BUILD_DIR)
	
# full clean: objects and binaries
full_clean: clean
	@echo "=== Cleaning binaries..."
	@$(RM) -rf $(TARGET_DIR)

	
############ PROGRAM_EXECUTION ############	
	
run_merger: all
	$(TARGET_DIR)/$(TARGET) -x merger -i $(DATA_DIR)/input_1 $(DATA_DIR)/input_2 $(DATA_DIR)/input_3 $(DATA_DIR)/input_4 -o $(DATA_DIR)/output_merger
	
run_converter: all
	$(TARGET_DIR)/$(TARGET) -x converter -i $(DATA_DIR)/output_merger -o $(DATA_DIR)/output_converter
	
run_seq_remover: all
	$(TARGET_DIR)/$(TARGET) -x seq_remover -i $(DATA_DIR)/input_1 $(DATA_DIR)/input_2 -o $(DATA_DIR) -s CCCAT TAAAC
