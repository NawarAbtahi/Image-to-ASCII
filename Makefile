# Compiler
CC = gcc

# Source and output
SRC = main.c
OUT = img_viewer

# Build rule
all: $(OUT)

$(OUT): $(SRC)
	$(CC) -o $(OUT) $(SRC) -lm

# Run the compiled program
run: $(OUT)
	./$(OUT)

# Clean up
clean:
	rm -f $(OUT)

