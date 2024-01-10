#include <stdio.h>
#include "./include/add.h"
#include "./include/config.h"
#include "./cm/cjson/cJSON.h"
#include <fcgi_stdio.h>
int main() {
    printf("Hello, World!\n");
    // 调用子函数并输出结果
    //int result = add(3, 5);
    //printf("The sum of 3 and 5 is: %d\n", result);
    //jsontest();
    //printf("Testing Xls\n");
    //TestXls();
    //ExcelToJson();
    //getplanTime();
    //getplanresult();
    //printf("zz1\n");
    //xlsTest();

    while (FCGI_Accept() >= 0) { // 循环处理每个请求
        printf("Content-type: text/plain\r\n\r\n"); // 设置响应类型为文本
        printf("Hello, World!\n");
    }
    return 0;
}

