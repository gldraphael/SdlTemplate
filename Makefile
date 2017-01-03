# The input files
INPUT_FILES = main.cpp

# The compiler to use
CC = clang++

# Compiler flags
COMPILER_FLAGS = -g

# Linker flags
LINKER_FLAGS = 

# The name of the output file
OUTPUT_FILE = app.out


all : $(INPUT_FILES)
	$(CC) $(INPUT_FILES) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUTPUT_FILE)