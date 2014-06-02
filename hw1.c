// Coursera Algorithms 1
// Author Anu Mercian
// Homework 1: Counting inversions
// Brute Force Method O(n^2)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long int getInverCount(unsigned long int inputArray[], unsigned long n)
{
	unsigned long int invCount = 0;
	unsigned long int i, j;

	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(inputArray[i]>inputArray[j])
				invCount++;

	return invCount;
}

int main(int argv, char** args)
{
	FILE *inputFile = fopen("IntegerArray.txt", "r");
	unsigned long int valuesRead,i=0;
	unsigned long int numberArray[100000];

	if(inputFile == NULL)
	{
		printf("ERROR: Can't open file \n");
		exit(8);
	}
	else
	{
		/* %d is for int, 
		 * %u for unsigned int 
		 *%lu for unsigned long int
         */
		fscanf(inputFile, "%lu", &valuesRead);
		while (!feof(inputFile))
		{
			//printf("%lu\n", valuesRead);
			numberArray[i] = valuesRead;
			i++;
			fscanf(inputFile, "%lu", &valuesRead);
		}
		printf("Number of inversions are %lu \n", getInverCount(numberArray, 100000));
	}
	fclose(inputFile);
	return 0;
}
