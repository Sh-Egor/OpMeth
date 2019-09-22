#include "Fucn.c"
#include <math.h>
#include <stdio.h>
#include <fcntl.h>

void
genData(int count)
{
	FILE* in = fopen("data.txt","w");
	for(int i = 0; i < count; i++){
		fprintf(in, "%lf %lf\n",(double)i, F((double)i));
	}
	fclose(in);
}

int
main(void)
{
	int count;
	printf("Enter count of dots\n");
	scanf("%d",count); 
	genData(count);
	system("gnuplot plot.scr");
	system("ristretto 1.png");
	return 0;
}