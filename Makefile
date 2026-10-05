CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -Isrc $(shell pkg-config --cflags raylib)
# Flagi linkera dla Raylib oraz zależności systemowe pod Linuksem
LIBS = $(shell pkg-config --libs raylib) -lm -lpthread -ldl -lrt -lX11

OBJ_DIR = .obj
BUILD_DIR = build
TARGET = $(BUILD_DIR)/openvk

# Główny plik z logiką OpenVK opartą o Raylib
OBJS = $(OBJ_DIR)/openvk.o

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $@ $(LIBS)

# Reguła kompilacji głównego pliku
$(OBJ_DIR)/openvk.o: src/openvk.c
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