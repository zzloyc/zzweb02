
CC = g++
CFLAGS = -std=c++11 -O2 -Wall -Wextra
LDFLAGS = -lfcgi

APP_NAME = main.fcgi
SRC_FILE = main.cpp

all: $(APP_NAME)

$(APP_NAME): $(SRC_FILE)
	$(CC) $(CFLAGS) $(SRC_FILE) -o $(APP_NAME) $(LDFLAGS)

clean:
	rm -f $(APP_NAME)