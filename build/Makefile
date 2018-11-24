# -*- MakeFile -*-

INCLUDE = ../include
SRC = ../src
CC = gcc
CFLAGS = -Wall

targets: server
	@echo ""
	@echo "ALL DONE"

server: server.o shared_memory.o sfunctions.o
	@echo ""
	@echo "Linking Server"
	$(CC) -I $(INCLUDE) $(FLAGS) $^ -o $@

server.o: $(SRC)/server.c
	@echo ""
	@echo "Compiling $<"
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

shared_memory.o: $(SRC)/shared_memory.c $(INCLUDE)/shared_memory.h
	@echo ""
	@echo "Compiling $<"
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

sfunctions.o: $(SRC)/sfunctions.c $(INCLUDE)/sfunctions.h
	@echo ""
	@echo "Compiling $<"
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

runs: server
	./server

help: 
	@echo ""
	@echo "O Make compilará dois executaveis:"
	@echo " - server"
	@echo " - user"
	@echo ""
	@echo "Para rodar o servidor:"
	@echo "> make run_server"
	@echo ""
	@echo "Para rodar o usuario:"
	@echo "> make run_user"
	@echo ""