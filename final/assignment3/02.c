#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int grade;
	char name[20];
	float gpa;
};

int main(){
	const char *filename="students.txt";
	FILE *fp=fopen(filename, "r");
	
	if(fp==NULL){
		perror(filename);
		return 1;
	}
	
	int capacity=10;
	int count=0;
	
	struct student *students=(struct student *)malloc(sizeof(struct student)*capacity);
	
	if(students==NULL){
		perror("malloc");
		fclose(fp);
		return 1;
	}
	
	while(fscanf(fp, "%d %d %s %f",
		&students[count].id,
		&students[count].grade,
		students[count].name,
		&students[count].gpa)==4){
		count ++;
		
		if(count==capacity){
			capacity +=10;
			struct student *temp=realloc(students, sizeof(struct student)*capacity);
		
			if(temp==NULL){
				perror("realloc");
				free(students);
				fclose(fp);
				return 1;
			}
			students=temp;
			}
		}
		fclose(fp);
		
		printf("---Student Information---\n");
		for(int i=0; i<count; i++){
			printf("ID: %d, Grade: %d, Name: %s, GPA: %.2f\n",
			students[i].id,
			students[i].grade,
			students[i].name,
			students[i].gpa);
		}
		printf("Total %d students.\n", count);
		
		free(students);
		return 0;
}									
