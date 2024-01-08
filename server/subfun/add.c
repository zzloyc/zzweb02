// addition.cpp 文件
#include "../include/add.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../cm/cjson/cJSON.h"
#include "../cm/libxls-1.6.2/include/xls.h"
// 函数定义
int add(int a, int b) {
    return a + b;
}

int xlsTest()
{
    xlsWorkBook* pWB;
    xlsWorkSheet* pWS;
    FILE *f;
    unsigned int i;

    xls_error_t code = LIBXLS_OK;
    struct st_row_data* row;
    WORD t,tt;
 
    //char path[] = "./tfile/zz02.xls";
    printf("zz1");
    pWB=xls_open_file("./tfile/zz02.xls", "UTF-8", &code);
    printf("zz2");
    if (pWB == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", "./tfile/zz02.xls", xls_getError(code));
        return 1;
    }

    f=fopen ("test.htm", "w");
    for (i=0;i<pWB->sheets.count;i++)
        printf("Sheet N%i (%s) pos %i\n",i,pWB->sheets.sheet[i].name,pWB->sheets.sheet[i].filepos);

    pWS=xls_getWorkSheet(pWB,0);
    if ((code = xls_parseWorkSheet(pWS)) != LIBXLS_OK) {
        fprintf(stderr, "Error parsing worksheet: %s\n", xls_getError(code));
        return 1;
    }

    fprintf(f,"<style type=\"text/css\">\n%s</style>\n",xls_getCSS(pWB));
    fprintf(f,"<table border=0 cellspacing=0 cellpadding=2>");

    for (t=0;t<=pWS->rows.lastrow;t++)
    {
        row=&pWS->rows.row[t];
        //		xls_showROW(row->row);
        fprintf(f,"<tr>");
        for (tt=0;tt<=pWS->rows.lastcol;tt++)
        {
            if (!row->cells.cell[tt].isHidden)
            {
                fprintf(f,"<td");
                if (row->cells.cell[tt].colspan)
                    fprintf(f," colspan=%i",row->cells.cell[tt].colspan);
                //				if (t==0) fprintf(f," width=%i",row->cells.cell[tt].width/35);
                if (row->cells.cell[tt].rowspan)
                    fprintf(f," rowspan=%i",row->cells.cell[tt].rowspan);
                fprintf(f," class=xf%i",row->cells.cell[tt].xf);
                fprintf(f,">");
                if (row->cells.cell[tt].str!=NULL && row->cells.cell[tt].str[0]!='\0')
                    fprintf(f,"%s",row->cells.cell[tt].str);
                else
                    fprintf(f,"%s","&nbsp;");
                fprintf(f,"</td>");
            }
        }
        fprintf(f,"</tr>\n");
    }
    fprintf(f,"</table>");
    printf("Count of rows: %i\n",pWS->rows.lastrow);
    printf("Max col: %i\n",pWS->rows.lastcol);
    printf("Count of sheets: %i\n",pWB->sheets.count);

    fclose(f);
    xls_showBookInfo(pWB);
    xls_close_WS(pWS);
    xls_close_WB(pWB);
    return 0;
}
