#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	const int nbrModels = 40, nbrIn = 1, nbrOut = 1;
	srand(time(NULL));
	unsigned int n,i;
	char pathOutput[80];
	FILE* output;

	printf("Output path : ");
	scanf("%s", pathOutput);

	output = fopen(pathOutput, "w+");

	fprintf(output, "%d %d %d\n\n", nbrModels, nbrIn, nbrOut);

	for(i=0; i<nbrModels;i++) {
		n=rand() % 500;
		fprintf(output, "%d\n\n%d\n\n",n, n*4+17);

	}
	printf("done. (in %s)\n", pathOutput);

	return 0;
}