// Coursera Algorithms 1
// Author Anu Mercian
// Homework 2: Counting comparisons using Quick Sort
// Method: Always select first element as pivot

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long int partition(long int inputArray[], long int left, long int right)
{
	long int i, j, pivot, temp;

	i = left + 1;
	pivot = inputArray[left];

	for(j=left+1; j<=right; j++)
	{
		if(inputArray[j] < pivot)
		{
			temp = inputArray[i];
			inputArray[i] = inputArray[j];
			inputArray[j] = temp;
			i += 1;
		}
	}
	
	temp = inputArray[i-1];
	inputArray[i-1] = inputArray[left];
	inputArray[left] = temp;

	return i-1;
}

long int quicksort(long int inputArray[], long int  left, long int  right)
{
	long int p, lc, rc, count=0;
	if (right - left <= 1)
		return 0;
	else
	{
		p = partition(inputArray, left, right);
		count = right-left-1;
		lc = quicksort(inputArray, left, p);
		//printf("\nleft count: %d", p-1-left);
		rc = quicksort(inputArray, p+1, right);
		//printf("\nright count: %d", right-p-1);
		return count + lc + rc;
	}
}

int main(int argv, char** args)
{
	FILE *inputFile = fopen("1000.txt", "r");
	long int valuesRead, compareCount, i=0;
	long int numberArray[1000];

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
			//printf("%d\n", valuesRead);
			numberArray[i] = valuesRead;
			i++;
			fscanf(inputFile, "%lu", &valuesRead);
		}
		compareCount = quicksort(numberArray, 0, 1000);

		/*printf("\n\nSorted array is:  ");
    	for(i = 0; i < 10; ++i)
        	printf(" %d ", numberArray[i]);*/

		printf("\nMethod 1:Number of comparisons are %lu \n", compareCount);
	}
	fclose(inputFile);
	return 0;
}
