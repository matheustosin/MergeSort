#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function for creating an input array||Update accoorind to your need
void generate_list(int *x, int n)
{
	int i, j, t;
	for (i = 0; i < n; i++)
		x[i] = i;
	for (i = 0; i < n; i++)
	{
		j = rand() % n;
		t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
}

void print_list(int *x, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", x[i]);
	}
}

// Merging 2 sorted subarrays into one tmp array
void merge(int *X, int n, int *tmp)
{
	int i = 0;
	int j = n / 2;
	int ti = 0;
	// i will iterate till first  half anf J will iterate for 2nd half of array
	while (i < n / 2 && j < n)
	{
		if (X[i] < X[j])
		{
			tmp[ti] = X[i];
			ti++;
			i++;
		}
		else
		{
			tmp[ti] = X[j];
			ti++;
			j++;
		}
	}
	while (i < n / 2)
	{ /* finish up lower half */
		tmp[ti] = X[i];
		ti++;
		i++;
	}
	while (j < n)
	{ /* finish up upper half */
		tmp[ti] = X[j];
		ti++;
		j++;
	}
	// Copy sorted array tmp back to  X (Original array)
	memcpy(X, tmp, n * sizeof(int));

} // end of merge()

void mergesort(int *X, int n, int *tmp)
{
	if (n < 2)
		return;

	mergesort(X, n / 2, tmp);

	mergesort(X + (n / 2), n - (n / 2), tmp);

// Wait for both paralel tasks to complete execution

	/* merge sorted halves into sorted list */
	merge(X, n, tmp);
}

int main()
{
	int n = 10;
	double start, stop;

	int data[MAX_SIZE], tmp[MAX_SIZE];

	generate_list(data, n);
	printf("List Before Sorting...\n");
	print_list(data, n);
	{
		mergesort(data, n, tmp);
	}
	printf("\nList After Sorting...\n");
	print_list(data, n);
}

/*output
	1. gcc mergeSort_sequencial.c -o merge
	2. time merge.exe
*/