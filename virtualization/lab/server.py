"""
HTTP Server

This program is a simple HTTP server built using Python's socket interface. The
objective of this lab is to "containerize" and run this application locally.

The application contains a single API endpoint "/" which logs some information
about the incoming request and simply returns a 200 response to the client.
"""

import socket
import logging

HOST = '127.0.0.1'
PORT = 8080
BUFSIZE = (1 << 12)

log = logging.getLogger("httpserver")
FORMAT = "[%(asctime)s] %(levelname)s %(message)s"

logging.basicConfig(format=FORMAT, level=logging.DEBUG)

def runServer():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind((HOST, PORT))
    server.listen(1)

    log.debug('server listening on %s:%s', HOST, PORT)

    with open('./data.txt', 'a') as data:
        while (True):
            try:
                conn, addr = server.accept()
                req = conn.recv(BUFSIZE).decode()

                data.write(req)
                data.flush()

                res = 'HTTP/1.1 200 OK\n\n'
                conn.sendall(res.encode())

            except Exception as e:
                log.error('error processing request: %s', e)

                res = 'HTTP/1.1 500 Internal Server Error\n\n'
                conn.sendall(res.encode())
            finally:
                conn.close()


    return server.close()

if __name__ == "__main__":
    runServer()

    print('fatal error. exiting...')
    exit(1)
