CC = g++
CFLAGS = -c -Wall

all: quadro

quadro: main.o ans.o test.o res.o
	$(CC) main.o ans.o test.o res.o -o quadro

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

ans.o: ans.cpp	
	$(CC) $(CFLAGS) ans.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp
	
res.o: res.cpp
	$(CC) $(CFLAGS) res.cpp
clean:
	rm -rf *.o quadro