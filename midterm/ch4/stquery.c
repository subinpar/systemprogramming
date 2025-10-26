#include <stdio.h>
#include "student.h"

int main(int argc, char *argv[])
{
	struct student rec;
	char c;
	int id;
	FILE *fp;
	
	if(argc!=2){
		fprintf(stderr, "sample: %s filename\n", argv[0]);
		return 1;
	}
	
	if((fp=fopen(argv[1],"rb"))==NULL){
		fprintf(stderr, "file open error\n");
		return 2;
	}
	
	do{
		printf("search id: ");
		if(scanf("%d", &id)==1){
			fseek(fp, (id-START_ID)*sizeof(rec), SEEK_SET);	
			if((fread(&rec, sizeof(rec), 1, fp)>0)&&(rec.id!=0))
				printf("id: %8d name: %4s score: %4d\n", rec.id, rec.name, rec.score);
			else printf("record %d X\n", id);
		}
		else printf("error");
		
		printf("continue?(Y/N)");
		scanf(" %c", &c);
	} while(c=='Y');
	
	fclose(fp);
	return 0;
}				
