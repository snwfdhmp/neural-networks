#include <fann.h>
#include <time.h>
#include <math.h>

#define NUMBER_OF_TEST 10
#define NUMBERS_TO_GEN 2
#define MAX 500

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	struct fann *ann = fann_create_from_file("trained_new.net");
	unsigned int i,j, errors = 0;
	float numbers[NUMBERS_TO_GEN];
	//printf("Nombres testés : \n");
	for (i = 0; i < NUMBER_OF_TEST; ++i)
	{	
		for (j = 0; j < NUMBERS_TO_GEN; ++j)
		{
			numbers[j] = rand() % MAX;
		}
		float *output = fann_run(ann, numbers);
		if(numbers[0]>numbers[1] != output[0])
			errors++;
		//printf("TEST : [%u] : [%u errors] %.f > %.f : %.f \n",i, errors, numbers[0], numbers[1], output[0]);
	}
	printf("\nTerminé ! %u erreurs effectuées\n", errors);
	return 0;
}