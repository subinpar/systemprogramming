#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc<2){
		printf("Usage: %s file1.txt\n", argv[0]);
		return 1;
	}
	
	for(int i=1; i<argc; i++){
		FILE *fp=fopen(argv[i],"rb");
		
		if(!fp){
			printf("NOT file: %s\n", argv[i]);
			continue;
		}
		
		fseek(fp, 0L, SEEK_END);
		long bytes=ftell(fp);
		fclose(fp);
		
		printf("Size of file[%s] is %ldBytes.\n", argv[i], bytes);
	}
	return 0;
}				
