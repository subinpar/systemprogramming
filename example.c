#include <stdio.h>

int main(void){
	FILE *fp=fopen("example.txt","w");
	if(fp==NULL){
		perror("fail");
		return 1;
	}

	printf("input text (Ctrl+D): ");

	char buf[4096];
	while (fgets(buf, sizeof(buf), stdin) !=NULL){
		fputs(buf,fp);
	}

	if(fclose(fp)!=0){
		perror("fail");	
		return 1;
	}

	puts("\nSaved to example.txt");
	return 0;
}
