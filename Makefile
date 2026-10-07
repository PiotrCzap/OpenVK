CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -Isrc $(shell pkg-config --cflags raylib)
# Flagi linkera dla Raylib oraz zależności systemowe pod Linuksem
LIBS = $(shell pkg-config --libs raylib) -lm -lpthread -ldl -lrt -lX11

OBJ_DIR = .obj
BUILD_DIR = build
TARGET = $(BUILD_DIR)/openvk

# Dodaliśmy tutaj main.o do listy obiektów do skompilowania i zlinkowania!
OBJS = $(OBJ_DIR)/openvk.o $(OBJ_DIR)/main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $@ $(LIBS)

# Reguła kompilacji pliku silnika
$(OBJ_DIR)/openvk.o: src/openvk.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Reguła kompilacji pliku głównego z grą (main.c)
$(OBJ_DIR)/main.o: src/main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	@clear
	@echo "--- openvk initialized with Raylib ---"
	@./$(TARGET)

clean:
	@rm -rf $(OBJ_DIR) $(BUILD_DIR)

push:
	@git add .
	@git commit -m "$(m)"
	@git push -u origin main

.PHONY: all run clean push