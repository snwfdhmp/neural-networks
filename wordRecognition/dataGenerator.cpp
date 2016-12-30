#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define PHRASE_LENGTH 11
#define WORD_FREQ 30
#define SPACE_FREQ 15

#define NBR_MODELS 2000
//#define WORD " METEO "

void insert(char* tab, unsigned int* i) {
	unsigned int j;
	char toBeInserted[]=" METEO ";
	unsigned int taille = strlen(toBeInserted);
	if(taille+*i < PHRASE_LENGTH){
		for (j = 0; j < taille; ++j)
			tab[*i+j] = toBeInserted[j];
	}
	*i = *i+j;
}

char randomChar() {
	char n;
	unsigned short int aleat;
	aleat = rand() % 100 +1;
	if(aleat <= SPACE_FREQ)
		return 32; //SPACE
	else
		return rand()%26+65; //a UPPERCASE char
}

void generatePhrase(char* phrase, bool *hasWord) {
	const int wordLength = strlen(" METEO ");
	unsigned int j, posWord;
	unsigned short int aleat;
	char n;


	aleat = rand() % 100 +1;
	*hasWord = (aleat <= WORD_FREQ);
	if (*hasWord)
		posWord = rand() % (PHRASE_LENGTH - (wordLength));

	for(j=0; j<PHRASE_LENGTH;j++) {
		if(*hasWord && posWord == j)
			insert(phrase, &j);
		else
			phrase[j] = randomChar();
	}
}


int main(int argc, char const *argv[])
{
	const int nbrModels = NBR_MODELS, nbrIn = PHRASE_LENGTH, nbrOut = 1;
	srand(time(NULL));
	unsigned int i, j;
	char pathOutput[80];
	bool hasWord;
	char phrase[PHRASE_LENGTH];
	FILE* output;

	printf("Output path : ");
	scanf("%s", pathOutput);

	output = fopen(pathOutput, "w+");

	fprintf(output, "%d %d %d\n\n", nbrModels, nbrIn, nbrOut);

	for(i=0; i<nbrModels;i++) {
		generatePhrase(phrase, &hasWord);
		printf("[%u]Phrase générée : %s\n", i, phrase);
		for(j=0; j<PHRASE_LENGTH; j++)
			fprintf(output, "%d ", phrase[j]);
		fprintf(output, "\n\n%d\n\n",hasWord);

	}
	printf("done. (in %s)\n", pathOutput);

	return 0;
}