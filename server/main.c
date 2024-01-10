#include <stdio.h>
#include "./include/add.h"
#include "./include/config.h"
#include "./include/sysconfig.h"
#include "./cm/cjson/cJSON.h"
#include <fcgi_stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
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


///////////////////////////////////

    while (FCGI_Accept() >= 0) { // 循环处理每个请求
        char buffer[BUFFER_SIZE];
        int len;

        // 获取Content-Length头，确定POST数据大小
        char* content_length_str = getenv("CONTENT_LENGTH");
        // 获取QUERY_STRING环境变量
        const char *query_string = getenv("QUERY_STRING");

       //printf("content_length_str:%s",content_length_str);
          
        if (!content_length_str) {
            // 如果没有Content-Length，则可能不是POST请求或不合法
            printf("Status: 411 Length Required\r\n");
            printf("\r\n");
            continue;
        }
       
        size_t content_length = atoi(content_length_str);
        printf("content_length:%d",content_length);
 
        // 读取POST数据
        len = FCGI_fread(buffer, sizeof(char), content_length, stdin);
        if (len != content_length) {
            continue;
        }
           cJSON *root = cJSON_Parse(buffer);
           cJSON *input_text_item = cJSON_GetObjectItem(root, "inputText");
            printf("Content-type: text/plain\r\n");
            printf("\r\n");
            printf("buffer:%s\n",buffer);
            printf("%s\n", input_text_item->valuestring);
            printf("query_string:%s\n",query_string);
    }
  
   //atest();
    return 0;
}

