#!/bin/bash

# 执行Makefile编译（假设Makefile在同一目录下）
make

# 如果编译成功并且生成了目标文件，例如假设目标文件名为"output"
if [ $? -eq 0 ]; then
    # 将编译后的文件移动到另一个位置，例如移动到"/target/directory/"
    rm /var/www/html/cgi-bin/main.fcgi
    echo "File removed successfully."
    mv main.fcgi /var/www/html/cgi-bin/main.fcgi
    echo "File moved successfully."
else
    echo "Make command failed. Not moving the file."
fi
