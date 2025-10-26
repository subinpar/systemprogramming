#include <stdio.h>
int main()
{
	int arr[10];
	int i, sum=0;
	
	printf("Enter 10 integers:\n");
	for(i=0; i<10; i++){
		scanf("%d", &arr[i]);
		}
	
	printf("Even numbers: ");
	for(i=0; i<10; i++){
		if(arr[i]%2==0){
			printf(" %d", arr[i]);
			sum+=arr[i];
			}
		}
		printf("\n");
		printf("sum of even numbers = %d", sum);
		
		return 0;
}		
	
				 
