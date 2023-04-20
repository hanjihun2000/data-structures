#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Choose an arbitrary number for the length of an array.
#define LENGTH 5

/*
*	Sorting Algoritms
*	---
*	Various sorting algorithms are as follows:
*		- Selection sort
*		- Bubble sort
*		- Insertion sort
*		- Merge sort
*		- Quick sort
*	---
*	Note:
*	argument "arr" indicates an array of integers to be sorted.
*	argument "len" represents the length of an array.
*/

static void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
};

void selectionSort(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		int smallest = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[smallest]) {
				swap(&arr[j], &arr[smallest]);
			}
		}
	}
};

void bubbleSort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = len - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
			}
		}
	}
};

void insertionSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
			swap(&arr[j], &arr[j - 1]);
		}
	}
};

// Merge two arrays.
static void merge(int result[], int arr1[], int arr2[], int len1, int len2) {
	int resultPoint = 0, arr1Point = 0, arr2Point = 0;
	while (arr1Point < len1 && arr2Point < len2) {
		if (arr1[arr1Point] < arr2[arr2Point])
			result[resultPoint++] = arr1[arr1Point++];
		else
			result[resultPoint++] = arr2[arr2Point++];
	}
	while (arr1Point < len1)
		result[resultPoint++] = arr1[arr1Point++];
	while (arr2Point < len2)
		result[resultPoint++] = arr2[arr2Point++];
}

void mergeSort(int arr[], int len) {
	if (len <= 1) {
		// If len is 0 or 1, an array is already sorted.
		return;
	}
	// An example of divide and conquer problem solving problem.
	// Divide an array into two sub-arrays.
	int len1 = len / 2; int len2 = len - len1;
	int* arr1 = (int*)malloc(sizeof(int) * len1);
	for (int i = 0; i < len1; i++) {
		arr1[i] = arr[i];
	}
	int* arr2 = (int*)malloc(sizeof(int) * len2);
	for (int i = 0; i < len2; i++) {
		arr2[i] = arr[len1 + i];
	}
	// Sort two sub-arrays.
	mergeSort(arr1, len1);
	mergeSort(arr2, len2);
	// Merge all arrays into a single "result".
	merge(arr, arr1, arr2, len1, len2);
}

static int findPivotAndRearrange(int arr[], int len) {
	// Normally, set the pivot value as the first element of an array.
	int pivot = arr[0];
	int x = 1; int y = len - 1;
	while (true) {
		// Right-hand side array should be larger than the pivot.
		while (arr[y] >= pivot && x != y) {
			y--;
		}
		// Left-hand side array should be smaller than the pivot.
		while (arr[x] < pivot && x != y) {
			x++;
		}
		if (x == y) 
			break;
		else 
			swap(&arr[x], &arr[y]);
	}
	if (arr[x] >= pivot) {
		return 0;
	}
	swap(&arr[x], &arr[0]);
	return x;
}

void quickSort(int arr[], int len) {
	if (len <= 1) {
		// If len is 0 or 1, an array is already sorted.
		return;
	}
	int pivotPoint = findPivotAndRearrange(arr, len);
	quickSort(arr, pivotPoint);
	quickSort(arr + pivotPoint + 1, len - (pivotPoint + 1));
}

int main() {
	int arr[LENGTH] = { 4, 8, 1, 3, 5 };
	
	// uncomment each line to check the sorting result

	//selectionSort(arr, LENGTH);

	//bubbleSort(arr, LENGTH);

	//insertionSort(arr, LENGTH);

	//mergeSort(arr, LENGTH);

	//quickSort(arr, LENGTH);

	for (int i = 0; i < LENGTH; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
