#include <fann.h>

int main(int argc, char const *argv[])
{
	char pathInput[80], pathOutput[80];
	unsigned int nbrCouches, *couches,i, essais = 20000;


	printf("Nombre de couches : ");
	scanf("%d", &nbrCouches);
	couches = (unsigned int*) malloc(sizeof(unsigned int) * nbrCouches);
	for (i = 0; i < nbrCouches; ++i)
	{
		printf("Nombre de neuronnes sur la couche n°%u : ", i+1);
		scanf("%u", &couches[i]);
	}
	printf("Training data : ");
	scanf("%s", pathInput);
	printf("Output : ");
	scanf("%s", pathOutput);
	printf("Nombre d'essais MAX : ");
	scanf("%u", &essais);

	struct fann *ann = fann_create_standard_array(nbrCouches, couches);
	
	fann_train_on_file(ann, pathInput, essais, 10, 0.00001);
	fann_save(ann, pathOutput);
	fann_destroy(ann);
	return 0;
}