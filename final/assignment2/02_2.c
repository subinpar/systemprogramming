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
	struct Employee e;
	int fd=open("employee", O_RDONLY);
	
	if(fd==-1){
		perror("Failed to open employee file");
		return 1;
	}
	
	printf("=== Employee Records ===\n");
	while (read(fd, &e, sizeof(e))==sizeof(e)){
	printf("ID: %d | NameL %=10s | Department: %-12s | Salary: %.2lf USD\n", e.emp_id, e.name, e.department,e.salary);
	}
	close(fd);
	return 0;
}			
