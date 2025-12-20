#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct Employee{
	int emp_id;
	char name[20];
	char department[20];
	double salary;
};

int main(void){
	struct Employee employees[]={
		{1001,"Alice","HR",3500.50},
		{1002,"Bob","Engineering",5200.75},
		{1003,"Charlie","sales",4100.00},
		{1004,"Trudy","Marketing",6100.00}
	};
	
	int fd=open("employee", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd==-1){
		perror("Faild to open employee file");
		return 1;
	}
	
	ssize_t bytes=write(fd, employees, sizeof(employees));
	if(bytes==-1){
		perror("Faild to write employee data");
		close(fd);
		return 1;
	}
	printf("Employee data written successfully.\n");
	close(fd);
	return 0;
}					
