import socket
import time


#Local host or other host
HOST = "127.0.0.1"
FILE_SIZE = 1024
PORT = 8080

skt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
skt.connect((HOST, PORT))
fileData = '1' * int(FILE_SIZE) * 1024 * 1024
fileData = fileData.encode()
print('start to send %d bytes data' % len(fileData))
start = time.time()
skt.sendall(fileData)
end = time.time()
result = (end - start) * 1000
print("sending 1GB data costs {} ms".format(result))
print("Network speed is {}GB/s".format(2000/result))
skt.close()