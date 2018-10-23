def server():
    s = socket(family, socktype, protocol)
    server_address = (host, port)

    binding = bind(s, server_address)
    listen(s, QueueLen)
    while (1):
        connection = accept(s)

        fork()
        if parent:
            close(connection)
        if child:
            close(s)
            handle_connection(connection)
            exit()

def client():
    s = socket(family, socktype, protocol)
    server_address = (host, port)

    connection = connect(s, server_address)

    send_request(s, Request)
    Response = read_response(s)
    handle_response(Response)

    close(s)
