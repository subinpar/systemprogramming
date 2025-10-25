#include <stdio.h>
#include <string.h>

#define FILE_PATH "books.txt"
#define LINE_MAX 512

int main(void){
	FILE *fp=fopen(FILE_PATH, "r");
	if(fp==NULL){
		perror(FILE_PATH);
		return 1;
	}
	
	char line[LINE_MAX];
	int idx=1;
	
	puts("=== Book List ===");
	
	while (fgets(line, sizeof(line), fp) != NULL){
		line[strcspn(line, "\r\n")]='\0';
		printf("Book %d=%s\n", idx++, line);
	}
	
	if(ferror(fp)){
		perror("fgets");
		fclose(fp);
		return 2;
	}
	fclose(fp);
	return 0;
}			
