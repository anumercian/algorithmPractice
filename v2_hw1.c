// Coursera Algorithms 1
// Author Anu Mercian
// Homework 1: Counting inversions
// Method 2: Merge Sort (mostly preferred)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function declarations

unsigned long int _mergeSort(unsigned long int arr[], unsigned long int temp[], unsigned long int left, unsigned long int right);
unsigned long int merge(unsigned long int arr[], unsigned long int temp[], unsigned long int left, unsigned long int mid, unsigned long int right);

/*Merge sort original code*/
unsigned long int mergeSort(unsigned long int arr[], unsigned long int array_size)
{
	unsigned long int *temp = (unsigned long int *)malloc(sizeof(unsigned long int)*array_size);
	return _mergeSort(arr, temp, 0, array_size-1);
}

/*Recursive Merge Sort*/
unsigned long int _mergeSort(unsigned long int arr[], unsigned long int temp[], unsigned long int left, unsigned long int right)
{
	unsigned long int mid, inv_count=0;
	if (right > left)
	{
		//Dividing into equal groups
		mid = (right+left)/2;

		//Inversion count is left subarray+right subarray+merge array
		inv_count  = _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid+1, right);

		inv_count += merge(arr, temp, left, mid+1, right);
	}
	return inv_count;
}

/*Merge of left and right subarrays*/
unsigned long int merge(unsigned long int arr[], unsigned long int temp[], unsigned long int left, unsigned long int mid, unsigned long int right)
{
	unsigned long int i, j, k;
	unsigned long int inv_count=0;

	i = left; //index of left subarray
	j = mid;  //index of right subarray
	k = left; //index of merged array
	while((i <= mid-1) && (j <=right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid-i);
		}
	}

	//copy elements to new array
	while (i <= mid-1)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	for (i=left; i<=right; i++)
		arr[i] = temp[i];

	return inv_count;
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
		fscanf(inputFile, "%d", &valuesRead);
		while (!feof(inputFile))
		{
			//printf("%d\n", valuesRead);
			numberArray[i] = valuesRead;
			i++;
			fscanf(inputFile, "%d", &valuesRead);
		}
		printf("Number of inversions are %lu \n", mergeSort(numberArray, 100000));
		fflush(NULL);
	}
	fclose(inputFile);
	return 0;
}
