#include<stdio.h>
#include "STRING_ST.h"
FILE *ptr;
char ch[255];// GV for file read buffer
char chunk;//GV for chunks
//int add;
int count=0;//Counter for loop return
int col=0,row=0;
char buff[255][6];
/****************Function to create file*************
 -----------------------------------------------------
input argument:

1. file_name---> Name of the file_create
2. file_oper---> Operation to perform
[w-write]
[r-read]
[ab-append]
----------------------------------------------------*/
int file_create(char *file_name,char *file_oper)
{
	ptr=fopen(file_name,file_oper);
	if(ptr==NULL)
	{
		printf("\nerror while creating file");
		return 0;
	}
	printf("\nfile created succesfully");
	return 0;
}
/****************************************************
*****************Function to Write data to file*******
 -----------------------------------------------------
input argument:

file_log---> data to appendinto the file
----------------------------------------------------*/


void file_write(char *file_log)
{
	fputs(file_log,ptr);
	printf("\nData written Succefullly");
	fclose(ptr);
//return 0;
}
//*****************************************************
/****************Function to Read file*************
 -----------------------------------------------------
input argument:

1. file_name---> Name of the file_create
----------------------------------------------------*/

int file_read(char *file_name)
{
    ptr=fopen(file_name,"r");
    	if(ptr==NULL)
	{
		printf("\nerror while Reading file.....");
		return 0;
	}
  while((fgets(ch,255,ptr))!=NULL) 
  {
  printf("\n%s",ch);
  }
  
 fclose(ptr); 
 return 0;  

}
//*****************************************************
/****************Function to Read chunks*************
 -----------------------------------------------------
input argument:

1. file_name---> Name of the file_create
----------------------------------------------------*/
int file_read_chunk(char *file_name)
{
    ptr=fopen(file_name,"r");
    	if(ptr==NULL)
	{
		printf("\nerror while Reading file chunks.....");
		return 0;
	}
 RET : while((chunk = fgetc(ptr)) != EOF) 
  {
      if(chunk==',')
      {   row++;
        col=0;
          //printf("\nCOUNTER IS=%d",count++);
          goto RET;
      }
buff[row][col]=chunk;
col++;
//printf("%c",chunk);
}
fclose(ptr);
row++; //to forcefully push value of row to max
for(int i=0;i<row;i++)//loop executes the contents of chunk
    for(int k=0;k<col;k++)
    {
        printf("%c",buff[i][k]);
    }
     printf("\n");
}
return 0;
}





