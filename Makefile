
main: main.cpp cepollclient.o
	g++ -o epoll_connection main.cpp cepollclient.o
cepollclient.o: cepollclient.cpp cepollclient.h
	g++ -c -o cepollclient.o cepollclient.cpp
clean:
	rm cepollclient.o main
run:
	make;./epoll_connection

	
