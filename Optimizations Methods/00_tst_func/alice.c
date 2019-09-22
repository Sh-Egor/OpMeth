#include <fcntl.h>
#include <stdio.h>

void
genFile(char* fucn)
{
	FILE* in = fopen("Fucn.c","w");
	fprintf(in, "double\n");
	fprintf(in, "F(double x)\n");
	fprintf(in, "{\n");
	fprintf(in, "	return %s;\n",fucn);
	fprintf(in, "}\n");
	fclose(in);
}

int
main(void)
{
	char func[200];
	printf("Enter function:\n");
	scanf("%s",func);
	genFile(func);

	return 0;
}