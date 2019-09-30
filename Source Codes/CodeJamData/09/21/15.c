#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <search.h>


typedef struct tagTree
{
	float weight;
	char feature[1024];
	struct tagTree * first;
	struct tagTree * second;
}Tree;

typedef struct tagAnimal
{
	char name[11];
	char features[100][11];
	int featureCount;
}Animal;

float chance;
Animal animals[100];
int AnimalCount;

int hasFeature (Animal * animal, char *feature)
{
	int i;

	for (i=0;i<animal->featureCount;i++)
	{
		if (strcmp (animal->features[i], feature) == 0)
			break;
	}

	return (i != animal->featureCount);
}

void isCute (Tree * base, Animal * animal)
{
	chance = chance * base->weight;
	if (base->first == NULL && base->second == NULL)
		return;
	if (hasFeature (animal, base->feature))
		isCute (base->first, animal);
	else
		isCute (base->second, animal);

}

void addTree (Tree * base, int which)
{
	if (which == 1)
		base->first = (Tree *) malloc (sizeof(Tree));
	else
		base->second = (Tree *) malloc (sizeof(Tree));
}

void leArvore (Tree * base, FILE * arq)
{
	int aux;
	int lendo1;
	int i;


	base->first = NULL;
	base->second = NULL;
	fscanf (arq, "%f", &base->weight);
	lendo1 = 1;
	while (1)
	{
		aux = fgetc(arq);
		if (aux == '(')
		{
			if (lendo1)
			{
				addTree (base, 1);
				leArvore (base->first, arq);
				lendo1 = 0;
			}
			else
			{
				addTree (base, 2);
				leArvore(base->second, arq);
			}
		}
		else if (aux == ')')
			return;
		else if (aux != ' ' && aux != '\n')
		{
			i = 0;
			do
			{
				base->feature[i++] = aux;
				aux = fgetc(arq);
			} while (aux != ' ' && aux != '\n');
			base->feature[i++] = '\0';
		}
	}
	
}

void freeArvore (Tree *base)
{
	if (base->first != NULL)
		freeArvore (base->first);
	if (base->second != NULL)
		freeArvore (base->second);
	free (base->first);
	free (base->second);

}
void main (void)
{
	FILE * inputFile;
	FILE * outputFile;
	int numCases;
	int i;
	int j,k;
	Tree root;
	int TreeLines;

	inputFile = fopen ("input.txt", "rt");
	if (inputFile == NULL)
	{
		puts ("File not found");
		return;
	}
	outputFile = fopen ("output.txt", "wt");
	if (outputFile == NULL)
	{
		puts ("Error creating file");
		return;
	}
	fscanf (inputFile,"%d",&numCases);

	for (i=0;i<numCases;i++)
	{
		fscanf (inputFile,"%d",&TreeLines);

		while (fgetc(inputFile) != '(');

		leArvore (&root, inputFile);
		fscanf (inputFile,"%d",&AnimalCount);
		for (j=0;j<AnimalCount;j++)
		{
			fscanf (inputFile,"%s",animals[j].name);
			fscanf (inputFile,"%d",&animals[j].featureCount);
			for (k=0;k<animals[j].featureCount;k++)
				fscanf (inputFile,"%s",animals[j].features[k]);
		}

		fprintf (stdout,	 "Case #%d:\n",i+1);
		fprintf (outputFile, "Case #%d:\n",i+1);
		for (j=0;j<AnimalCount;j++)
		{
			chance = 1;
			isCute(&root, &animals[j]);
			fprintf (stdout, "%f\n",chance);
			fprintf (outputFile, "%f\n",chance);
		}
		freeArvore (&root);
	}


	fclose (inputFile);
	fclose (outputFile);
}