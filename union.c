#include <stdio.h>
#include <string.h>

union Data {
	int i;
	float f;
	char str[20];
};

int main(void) {
	union Data d;
	
	d.i=123;
	printf("[d.i=123;]\n");
	printf("d.i=%d\n",d.i);
	printf("d.f=%f\n",d.f);
	printf("d.str=%s\n\n",d.str);

	d.f=3.14159;
	printf("[d.f=3.14159;]\n");
	printf("d.i=%d\n",d.i);
	printf("d.f=%f\n",d.f);
	printf("d.str=%s\n\n",d.str);

	strcpy(d.str,"hello");
	printf("[strcpy(d.str,\"hello\");]\n");
	printf("d.i=%d\n",d.i);
	printf("d.f=%f\n",d.f);
	printf("d.str=%s\n\n",d.str);

	printf("union data size = %lu bite\n",sizeof(d));
	
	return 0;
}
