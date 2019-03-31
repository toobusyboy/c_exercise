#include <stdio.h>

int func1(const char *str)
{
	printf("func1 : %s\n",str);
	return 0;
}

int func2(const char *str)
{
	printf("func2 : %s\n",str);
	return 0;
}

int main(int argc, const char *argv[])
{
	char str[2] = {0};

	void *array[2] = {func1,func2};

	int (*(*func_ptr))(const char *) = (int (*(*))(const char *))array; 
	for(int i = 0 ; i < 2 ;i ++)
	{
		sprintf(str,"%d",i);
		((int (*)(const char *))*(func_ptr+i))(str);
	}


	int (*(*func_arrary_ptr)[2])(const char *) = (int (*((*)[2]))(const char *))&array;
	for(int i = 0 ; i < 2 ;i ++)
	{
		sprintf(str,"%d",i);
		((int (*)(const char *))*(*func_arrary_ptr+i))(str);
	}

	int (*func_arrary[2])(const char *) = {func1,func2};
	for(int i = 0; i < 2 ;i ++)
	{
		sprintf(str,"%d",i);
		func_arrary[i](str);
	}

	return 0;
}
