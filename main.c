#include<stdio.h>
#include "STRING_ST.h"
int main()
{

	char data_log[255];
	//file_create("hexa.txt","a");
	for(int i=0; i<256; i++)
	{
		if(i==255)
		{
			file_create("hexa.txt","a");
			sprintf(data_log, "0x%x",DATA+i);
			file_write(data_log);
		}
		else {
			file_create("hexa.txt","a");
			sprintf(data_log, "0x%x,", DATA+i);
			file_write(data_log);
		}
	}
	//file_create("hexa.txt","r");
	printf("\n");
	file_read_chunk("hexa.txt");
	return 0;
}
