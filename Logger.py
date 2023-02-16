from socket import *
from os.path import exists

# create server socket
server_socket = socket(AF_INET, SOCK_STREAM)
# bind socket to port number
server_socket.bind(('', 7779))
# keep socket listening to connections
server_socket.listen(1)
print("Server is ready to connect...\n")

# run forever loop to connect and receive messages
while(True):
    # create connection socket
    connection_socket, address = server_socket.accept()    
    print("HTTP request:")

    # receive message from connection socket
    request = connection_socket.recv(2048)
    print("{}\n".format(request.decode()))
    if (request.decode() == "Melon"):
        while(True):
            request = connection_socket.recv(2048)
            print("{}\n".format(request.decode()))

    connection_socket.close()
