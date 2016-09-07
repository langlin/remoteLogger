import sys
import zmq
import socket

#myip = socket.gethostbyname(socket.gethostname())
myip = '172.16.41.101'
print (myip)

port = "5556"
if len(sys.argv) > 1:
    port =  sys.argv[1]
    int(port)
    
if len(sys.argv) > 2:
    port1 =  sys.argv[2]
    int(port1)

# Socket to talk to server
context = zmq.Context()
socket = context.socket(zmq.SUB)

print ("Collecting updates from weather server...")
socket.connect ("tcp://"+myip+":"+port)

if len(sys.argv) > 2:
    socket.connect ("tcp://"+myip+":"+port1)

# Subscribe to zipcode, default is NYC, 10001
topicfilter = ""
#topicfilter = ""
socket.setsockopt_string(zmq.SUBSCRIBE, topicfilter)

# Process 5 updates
total_value = 0
while True:
    string = socket.recv()
    print ("Received :", string)

