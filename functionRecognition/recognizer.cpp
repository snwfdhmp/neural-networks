#include <fann.h>
#include <time.h>
#include <math.h>

#define NUMBERS_TO_GEN 2
#define MAX 500

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	struct fann *ann = fann_create_from_file("trained.net");
	int i;
	float numbers[NUMBERS_TO_GEN];
	printf("Nombres testés : \n");
	for (i = 0; i < NUMBERS_TO_GEN; ++i)
	{
		numbers[i] = rand() % MAX;
		printf("%f ", numbers[i]);
	}

	float *output = fann_run(ann, numbers);
	printf("\na>b : %f\na <=b : %f\n", output[0], output[1]);
	return 0;
}