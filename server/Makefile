# Makefile

# 可执行文件名
EXECUTABLE := main

# 源代码文件列表
SOURCES := main.c \
          subfun/add.c \
		  subfun/config.c \
		  cm/cjson/cJSON.c \
		  cm/libxls-1.6.2/src/endian.c \
		  cm/libxls-1.6.2/src/locale.c \
		  cm/libxls-1.6.2/src/ole.c \
		  cm/libxls-1.6.2/src/xls.c \
		  cm/libxls-1.6.2/src/xlstool.c

# 头文件目录（如果有的话）
INCLUDES := include

# 编译器和编译选项
CC := gcc
CFLAGS := -std=gnu11 -Wall -g -I$(INCLUDES)


# 链接时所需的库
LIBS = -lxlsreader


# 目标对象文件列表
OBJECTS := $(SOURCES:.c=.o)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -lm -o $@ $(LIBS)

# 从.cpp生成.o的规则
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理目标
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)