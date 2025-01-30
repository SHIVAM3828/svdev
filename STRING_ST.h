#include<stdio.h>
#define DATA        0x05
int  file_create(char *file_name,char *file_oper);
void file_write(char *file_log);
int file_read(char *file_name_r);
int file_read_chunk(char *file_name);