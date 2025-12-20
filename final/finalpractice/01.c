#include <stdio.h>
#include <string.h>

int main(){
	char studentId[20];
	char name[20];
	char residentId[20];
	char phone[20];
	float gpa;
	
	printf("Student ID: ");
	scanf("%s", studentId);
	
	printf("Name: ");
	scanf("%s", name);
	
	printf("Resident ID: ");
	scanf("%s", residentId);
	
	printf("Phone: ");
	scanf("%s", phone);
	
	printf("GPA: ");
	scanf("%f", &gpa);
	
	printf("\n===Masked Output===\n");
	printf("Student ID: %s\n", studentId);
	printf("Name      : %s\n", name);
	
	printf("Resident ID: ");
	printf("%.7s", residentId);
	printf("%c", residentId[7]);
	for(int i=0; i<6; i++){
		printf("*");
	}
	printf("\n");
	
	printf("Phone     : %s\n",phone);
	printf("GPA       : ***\n");
	
	return 0;
}		  
