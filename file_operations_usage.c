#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	FILE *f;
	char c[] ="This is a temporary file";
	char *buffer = NULL;
	buffer = (char *)malloc(sizeof(char) * 100);
	
	char buf[100];
	
	f = fopen("Temp.txt", "w+");
	printf("Opened a file\n");
	fwrite(c, sizeof(char), strlen(c)+1, f);
	printf("Finished writing  the string to the file\n");

	fseek(f, 0, SEEK_SET);
	printf("Seeking to the beginning of the file\n");
	
	printf("Size of char: %d \n", sizeof(c));

	//If you gave sizeof(c) below instead of sizeof(char) - you will get a seg fault since you will be getting the number of bytes in c i.e length of c * number of bytes in the datatype of c
	fread(buffer, sizeof(char), strlen(c)+1, f);
	printf("%s", buffer);
	
	fclose(f);
	return 0;

}
