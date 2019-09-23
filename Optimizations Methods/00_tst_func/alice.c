#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

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
	pid_t pid;
	char func[200];
	int status;
	printf("Enter function:\n");
	scanf("%s",func);
	genFile(func);
	if(pid == fork()){
		wait(&status);
		execlp("./bob.out","bob.out",NULL);
	}else{
		system("gcc bob.c -lm -o bob.out");
		_exit(0);
	}
	return 0;
}