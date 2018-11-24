# -*- MakeFile -*-

INCLUDE = ../include
SRC = ../src
CC = gcc
CFLAGS = -Wall
FLAGS =

targets: server client
	@echo ""
	@echo "ALL DONE"

server: server.o shared_memory.o sfunctions.o message_queue.o
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

message_queue.o: $(SRC)/message_queue.c $(INCLUDE)/message_queue.h
	@echo ""
	@echo "Compiling $<"
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

sfunctions.o: $(SRC)/sfunctions.c $(INCLUDE)/sfunctions.h $(INCLUDE)/macros.h
	@echo ""
	@echo "Compiling $<"
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

client: client.o cfunctions.o message_queue.o
	@echo ""
	@echo "Linking Client"
	$(CC) -I $(INCLUDE) $(FLAGS) $^ -o $@

client.o: $(SRC)/client.c
	@echo ""
	@echo "Compiling $<"
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

cfunctions.o: $(SRC)/cfunctions.c $(INCLUDE)/cfunctions.h
	@echo ""
	@echo "Compiling $<"
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

runs: server
	./server

runc: client
	./client

help: 
	@echo ""
	@echo "O Make compilará dois executaveis:"
	@echo " - server"
	@echo " - client"
	@echo ""
	@echo "Para rodar o servidor:"
	@echo "> make runs"
	@echo ""
	@echo "Para rodar o client:"
	@echo "> make runc"
	@echo ""