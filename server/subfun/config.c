#include "../include/config.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../cm/cjson/cJSON.h"
#include <xls.h>

// 初始化链表
StringListNode* initStringList() {
    printf("StringListNode_Init\n");
    return NULL;
}

// 添加字符串到链表（确保不重复）
void addStringToList(StringListNode** list, const char* str) {

// || !isInList(list, str)
    if (*list == NULL|| !isInList(*list, str)) {

        StringListNode* newNode = (StringListNode*)malloc(sizeof(StringListNode));
 
        int len = sizeof(str)+1;
        char* temp = (char*) malloc(len);
        memset(temp,0,len);
        strcpy(temp,str);
        newNode->value = temp;
//        printf("str:%s\n",str);
        newNode->next = *list;
        *list = newNode;
    }
   //printf("List:%s\n",(*list)->value);
   //printf("List:%s\n",(*list)->value);
}

// 检查链表中是否已存在给定的字符串

int isInList(const StringListNode* list, const char* str) {
   
    if (list == NULL) {
        return 0;
    }
    
    for (const StringListNode* node = list; node != NULL; node = node->next) {
        if (strcmp(node->value, str) == 0) {
            return 1;
        }
    }
    return 0;
}

// 删除链表中的指定字符串
void removeStringFromList(StringListNode** list, const char* str) {
    StringListNode* prev = NULL;
    StringListNode* curr = *list;

    while (curr != NULL) {
        if (strcmp(curr->value, str) == 0) {
            if (prev == NULL) {
                *list = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr->value);
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

// 将链表转换为JSON格式
cJSON* convertToStringArrayToCJSON(const StringListNode* list) {
    cJSON* jsonArray = cJSON_CreateArray();

    for (const StringListNode* node = list; node != NULL; node = node->next) {
        cJSON_AddItemToArray(jsonArray, cJSON_CreateString(node->value));
    }

    return jsonArray;
}

// 清空并释放整个链表
void clearStringList(StringListNode** list) {
    while (*list != NULL) {
        StringListNode* toDelete = *list;
        *list = (*list)->next;

        free(toDelete->value);
        free(toDelete);
    }
}


int SetString(){
    //printf("SetString_start1\n");
    StringListNode* stringList = initStringList();

    // 添加字符串
    addStringToList(&stringList, "123");
    addStringToList(&stringList, "banana");
    addStringToList(&stringList, "cherry");

    // 转换为JSON
    cJSON* json = convertToStringArrayToCJSON(stringList);
    char* jsonStr = cJSON_Print(json);
    cJSON_Delete(json);
    
    printf("JSON array: %s\n", jsonStr);
    free(jsonStr);
// 清空并释放整个链表
    clearStringList(&stringList);

}

void jsontest(){

    cJSON *cjson, *test_1,*test_2, *test_3;
    char *json_string = "{\"test_1\":\"0\",\"test_2\":\"1\",\"test_3\":2}";

    cjson = cJSON_Parse(json_string);
    if(cjson == NULL)
    {   
        printf("json pack into cjson error...\n");
    }   
    else
    {   
        cJSON_Print(cjson);
    }   
    test_1 = cJSON_GetObjectItem(cjson, "test_1");
    test_2 = cJSON_GetObjectItem(cjson, "test_2");
    test_3 = cJSON_GetObjectItem(cjson, "test_3");
    printf("%s\n", test_1->valuestring);
    printf("%s\n", test_2->valuestring);
    printf("%d\n", test_3->valueint);

    cJSON_Delete(cjson);

}

int TestXls(){
 xlsWorkBook *pWb = NULL;
    xlsWorkSheet *pWs = NULL;    
    xlsRow *row_current = NULL;
    int row = 0, col = 0;
 
    const char code[]="UTF-8";
    printf("start:test xls");
    pWb = xls_open("./tfile/zz02.xls",code);
    if (NULL==pWb){ 
        printf("File open error!\n");  
        return -1;  
    }
 
    pWs = xls_getWorkSheet(pWb, 0);//pWs指向第二个Sheet
    xls_parseWorkSheet(pWs);
    for (row=0; row<=pWs->rows.lastrow; row++){  
        row_current = &(pWs->rows.row[row]);//提取行
        for (col=0; col<=pWs->rows.lastcol; col++){//遍历列
            if(row_current->cells.cell[col].str!=NULL)//
            {
                    printf("%s\t",row_current->cells.cell[col].str);
            }
        }
        printf("\n");
    }
    xls_close_WS(pWs);
    xls_close_WB(pWb);
 
    return 0;
}

//Excel文件解析函数，将解析结果存储为Json格式

int ExcelToJson(){
   
	//const char *xls_filename = "./tfile/zz01.xls";
	//printf("in_to_Json");
	xls_error_t error;
    
    xlsWorkBook *pWorkBook = xls_open_file("./tfile/zz02.xls", "UTF-8", &error);
    
    if (pWorkBook == NULL) {
        fprintf(stderr, "Error opening Excel file: %s\n", xls_getError(error));
		printf("failed");
		return -1;
    }

    // 获取第一个工作表
    xlsWorkSheet *pWorkSheet = xls_getWorkSheet(pWorkBook, 0);
    if (pWorkSheet == NULL) {
        fprintf(stderr, "Error opening first worksheet\n");
        xls_close_WB(pWorkBook);
        printf("failed");
		return -1;
    }

    // 解析工作表
    if (xls_parseWorkSheet(pWorkSheet) != LIBXLS_OK) {
        fprintf(stderr, "Error parsing worksheet\n");
        xls_close_WS(pWorkSheet);
        xls_close_WB(pWorkBook);
        printf("failed");
		return -1;
    }
	//printf("success parsing worksheet\n");
	int numRows = pWorkSheet->rows.lastrow;
    int numCols = pWorkSheet->rows.lastcol;

	int hour[numRows];
	int mintes[numRows];
	float power[numRows];
    //printf("Number of rows: %d\n", numRows);
    //printf("Number of columns: %d\n", numCols);

   // 初始化日期字符串数组
    cJSON *plandata = cJSON_CreateArray();
    StringListNode* Timedata = initStringList();
	cJSON *temp;
	xlsCell *cell;
	
	// 遍历Excel表格中的数据
	for (int row = 1; row <= numRows; ++row){
		//printf("\nrow:%d",row);
		   	temp = cJSON_CreateObject();
		  	cell = xls_cell(pWorkSheet, row, 0);
		   	if(cell->d == 0){
			   break;
			   };
            /**/
			char Date[21];
            memset(Date, 0, sizeof(Date)); // 初始化为零以确保字符串结束
			if((int)xls_cell(pWorkSheet, row, 0)->d < 0 || (int)xls_cell(pWorkSheet, row, 1)->d > 12 || (int)xls_cell(pWorkSheet, row, 1)->d < 0 || (int)xls_cell(pWorkSheet, row, 2)->d > 31 || (int)xls_cell(pWorkSheet, row, 2)->d < 0){
				//output("failed");
				return -1;
				};
			snprintf(Date,sizeof(Date),"%d-%d-%d",(int)xls_cell(pWorkSheet, row, 0)->d,(int)xls_cell(pWorkSheet, row, 1)->d,(int)xls_cell(pWorkSheet, row, 2)->d);
			cJSON_AddItemToObject(temp,"Date", cJSON_CreateString(Date));
             addStringToList(&Timedata, Date);
		
			//Date = NULL;
			
			if((int)xls_cell(pWorkSheet, row, 3)->d < 0 || (int)xls_cell(pWorkSheet, row, 3)->d > 24 || (int)xls_cell(pWorkSheet, row, 4)->d < 0 || (int)xls_cell(pWorkSheet, row, 4)->d > 60){
				//output("failed");
				return -1;
				};

			char StartTime[21];
            memset(StartTime, 0, sizeof(StartTime));
			snprintf(StartTime,sizeof(StartTime),"%d:%d",(int)xls_cell(pWorkSheet, row, 3)->d,(int)xls_cell(pWorkSheet, row, 4)->d);

			cJSON_AddItemToObject(temp,"StartTime", cJSON_CreateString(StartTime));
	

			if((int)xls_cell(pWorkSheet, row, 5)->d < 0 || (int)xls_cell(pWorkSheet, row, 5)->d > 24 || (int)xls_cell(pWorkSheet, row, 6)->d < 0 || (int)xls_cell(pWorkSheet, row, 6)->d > 60){
				//output("failed");
				return -1;
				};

			char EndTime[21];
            memset(EndTime, 0, sizeof(EndTime));
			snprintf(EndTime,sizeof(EndTime),"%d:%d",(int)xls_cell(pWorkSheet, row, 5)->d,(int)xls_cell(pWorkSheet, row, 6)->d);

		    cJSON_AddItemToObject(temp,"EndTime", cJSON_CreateString(EndTime));
		

			if((int)xls_cell(pWorkSheet, row, 7)->d < -200 || (int)xls_cell(pWorkSheet, row, 7)->d > 200){
				//output("failed");
				return -1;
				};			
		   	cell = xls_cell(pWorkSheet, row, 7);
		   	cJSON_AddItemToObject(temp,"power", cJSON_CreateNumber((int)cell->d));

		   	cJSON_AddItemToArray(plandata,temp);
            //cJSON_Delete(temp);
	   }

        cJSON_Delete(temp);
		//将arraydata数组中的所有日期，存储到Timedata  cJSON数据中
 

    cJSON* PlanTime = convertToStringArrayToCJSON(Timedata);
	char *tmp_cjson = cJSON_Print(PlanTime);
	cJSON_Delete(PlanTime);
  
    clearStringList(&Timedata);
	printf("Timedata=%s\n",tmp_cjson);
 	FILE *fp1 = NULL;	
	 fp1 = fopen("./tfile/PlanTime.json", "w+");
	 if(NULL!=fp1)
	 {
		 fwrite(tmp_cjson,strlen(tmp_cjson),1,fp1);
		 fflush(fp1);
		 fclose(fp1);
	 }
	free(tmp_cjson);

    tmp_cjson = cJSON_Print(plandata);
	cJSON_Delete(plandata);
	 //printf("\ndata=%s\n",tmp_cjson); 
	fp1 = fopen("./tfile/PlanMode.json", "w+");
  
	if(NULL!=fp1)
	 {
		 fwrite(tmp_cjson,strlen(tmp_cjson),1,fp1);
		 fflush(fp1);
		 fclose(fp1);
         printf("success_write\n");
	 }else{

        printf("false_write\n");
	 };

	free(tmp_cjson);
    xls_close_WS(pWorkSheet);
    xls_close_WB(pWorkBook);
    return 0;
}


//从文件中获取计划曲线时间数据并处理
int getplanTime(){
	 // 打开计划时间数据文件
    FILE *file = fopen("./tfile/PlanTime.json", "r");
    if (file != NULL) {

        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);


        char *jsonData = (char *)malloc(fileSize + 1);
        fread(jsonData, 1, fileSize, file);
        jsonData[fileSize] = '\0';    // 在jsonData末尾添加null字符
        fclose(file);
        printf("PlanTime:%s\n",jsonData);
        printf("\n");
        free(jsonData);
    } else {
        printf("failed");
		return -1;
    }

    return 0;
}

int getplanresult(){
	
    char *Set_Time= "2023-12-7";
	// ?????
    printf("getplanresult\n");
    FILE *file = fopen("./tfile/PlanMode.json", "r");
    if (file != NULL) {
        
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);
        
        char *jsonData = (char *)malloc(fileSize + 1);
        fread(jsonData, 1, fileSize, file);
        jsonData[fileSize] = '\0';  
		cJSON *ResData = cJSON_Parse(jsonData);
		free(jsonData);
		char *tmp_cjson = cJSON_Print(ResData);
		//printf("ResData=%s\n",tmp_cjson);
		cJSON *SendData = cJSON_CreateArray();
		cJSON *currentElement = ResData->child;

		while (currentElement != NULL) {
        // 在这里你可以访问当前元素的属性
        cJSON *Date = cJSON_GetObjectItem(currentElement, "Date");//halfdelay
        char *temp = Date->valuestring;
		//printf("Date->valuestring: %s\n", temp);
        if(strcmp(Set_Time,temp) == 0){
			cJSON_AddItemToArray(SendData,cJSON_Duplicate(currentElement, 1));	
			};
        // 移动到下一个元素
        currentElement = currentElement->next;
    }
    free(tmp_cjson);
    tmp_cjson = cJSON_Print(SendData);
	printf("SendData=%s\n",tmp_cjson);
		//printf(tmp_cjson);
		free(tmp_cjson);
        fclose(file);   
		cJSON_Delete(ResData);
		cJSON_Delete(SendData);       

    } else {
        printf("failed");
		return -1;
    }

    return 0;
}