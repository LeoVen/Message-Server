# Message-Server

A message server using message queues and shared memory segments.

There are two applications that can run on different terminals:

* server
* client

The server must be initialized only once. The client can be initialized by many terminals at once where they can send several messages to the server. The server has some basic functions that retrieve system information and these will be written in a shared memory location to then be read by the client. There is also a flag that signals to whom the message goes to as the server will be receiving multiple requests from multiple clients.
