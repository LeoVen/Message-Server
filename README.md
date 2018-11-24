# Message-Server

A message server using message queues and shared memory segments.

There are two applications that can run on different terminals:

* server
* user

The server must be initialized only once. The user can be initialized by many terminals at once where they can send several messages to the server.
