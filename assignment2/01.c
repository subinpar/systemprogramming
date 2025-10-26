#include <stdio.h>
#include <string.h>

int main(void){
	FILE *fp=fopen("books.txt", "r");
	if(fp==NULL){
		perror("books.txt");
		return 1;
	}
	
	char line[200];
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
