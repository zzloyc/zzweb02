#include <stdio.h>
#include <xls.h>
//#include "readxls.h"
 
int main()
{
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
 