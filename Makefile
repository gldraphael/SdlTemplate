# The input files
INPUT_FILES = main.cpp Application.cpp

# The compiler to use
CC = clang++

# Compiler flags
COMPILER_FLAGS = -g -std=c++11

# Linker flags
LINKER_FLAGS = -lSDL2

# The name of the output file
OUTPUT_FILE = app.out


all : $(INPUT_FILES)
	$(CC) $(INPUT_FILES) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUTPUT_FILE)
