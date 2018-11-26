# -*- MakeFile -*-

INCLUDE = ../include
SRC = ../src
CC = gcc
CFLAGS = -Wall
FLAGS =

targets: server client
	@echo ""
	@echo "ALL DONE"

server: server.o shared_memory.o message_queue.o sfunctions.o
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

sfunctions.o: $(SRC)/sfunctions.c $(INCLUDE)/sfunctions.h
	@echo ""
	@echo "Compiling $<"
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

client: client.o shared_memory.o message_queue.o cfunctions.o
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

clear:
	rm -f *.o
	rm server client

help: 
	@echo ""
	@echo "This makefile will produce two executables:"
	@echo " - server"
	@echo " - client"
	@echo ""
	@echo "To run the server:"
	@echo "> make runs"
	@echo ""
	@echo "To run the client:"
	@echo "> make runc"
	@echo ""