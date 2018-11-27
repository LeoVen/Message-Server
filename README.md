# Message-Server

A message server using message queues and shared memory segments.

There are two applications that can run on different terminals:

* server
* client

The server must be initialized only once. The client can be initialized by many terminals at once where they can send several messages to the server. The server has some basic functions that retrieve system information and these will be written in a shared memory location to then be read by the client. There is also a flag that signals to whom the message goes to as the server will be receiving multiple requests from multiple clients.

There is only one message queue to communicate with the server and there are two memory segments:

* result (resulting answer from the server)
* receiver (to whom the result should go to)

When the server is up it will start by reading the next message in the queue. If there is none it will be waiting until some message appears. After receiving a message it will use that to decide which command to return to the client. It is possible to obtain the process id from whom sent the message. If it is a valid command the server will produce a result and this will be added to the `result` memory segment and the process id will be added to the `receiver` memory segment.

The client after sending a message to the server will read the answer if the `receiver` memory segment contains the the same number as the client's process id. The client has a timeout to receive the message. Also, before sending the message the client must set the `receiver` memory segment to `0` to prevent reading its own previous messages (if it was the only client sending messages). If the `receiver` memory segment is set to `-1` then it was an invalid command.

Type in `help` in the client to see all available commands.