#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc<2){
		printf("Usage: %s file1.txt [file2.txt ...]\n", argv[0]);
		return 1;
	}
	
	for(int i=1; i<argc; i++){
		printf("%d. Filename: %s\n", i, argv[i]);
		
		FILE *fp=fopen(argv[i], "r");
		
		if(!fp){
			printf("NOT file: '%s'\n", argv[i]);
			printf("========================================\n");
			continue;
		}
		
		char c[1024];
		while (fgets(c, sizeof(c), fp)){
			printf(c,stdout);
		}
		fclose(fp);
		
	printf("======================================\n");
	}
	return 0;
}
					
