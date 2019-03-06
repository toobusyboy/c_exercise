#include <stdio.h>

int func(void){ printf("func\n");}

int func1(void){ printf("func1\n");}

int main(int argc, const char *argv[])
{
	void *a[2] = {func,func1};

	void (*(*a_ptr)[2])(void) = (void (*(*)[2])(void))&a;

	for(int i = 0; i < sizeof(a)/sizeof(a[0]);i++)
	{
		((void (*)(void))(*(*a_ptr+i)))();
	}

	void* (*a_ptr1)[2] = &a;

	for(int i = 0 ; i < sizeof(a)/sizeof(a[0]); i++)
	{
		((void (*)(void))*(*a_ptr1+i))();
	}


	void* a_ptr2 = a;

	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		//(*(a_ptr2+i))();
		((void (*)(void))*(a_ptr2+i))();
	}

	return 0;
}
