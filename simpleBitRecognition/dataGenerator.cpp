#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define NBR_MODELS 2000
//#define WORD " METEO "


int main(int argc, char const *argv[])
{
	const int nbrModels = NBR_MODELS, nbrIn = 1, nbrOut = 1;
	srand(time(NULL));
	unsigned int i, j;
	char pathOutput[80];
	bool n;
	FILE* output;

	printf("Output path : ");
	scanf("%s", pathOutput);

	output = fopen(pathOutput, "w+");

	fprintf(output, "%d %d %d\n\n", nbrModels, nbrIn, nbrOut);

	for(i=0; i<nbrModels;i++) {
		n = rand() % 2;
		fprintf(output, "%d.00000\n\n%d.00000\n\n",n, !n);

	}
	printf("done. (in %s)\n", pathOutput);

	return 0;
}