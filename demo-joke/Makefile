PBSDK ?= /home/squale/developpement/PBSDK
CC = $(PBSDK)/bin/arm-obreey-linux-gnueabi-g++

CFLAGS = -Wall -Wextra -Wvla -Wmissing-field-initializers -Wshadow -Wno-unused-parameter -Wno-unused-function


all: demo-joke.app

demo-joke.app: demo-joke.cpp
	$(CC) demo-joke.cpp $(CFLAGS) -o demo-joke.app -linkview -lcurl -g -gdwarf-3

clean:
	rm -f demo-joke.app
