#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int arr[], int len) {
	int i,j,temp;

	for (i = 0; i < len-1; i++) {
		for (j = i; j < len; j++) {
			if (arr[j] < arr[i]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	return 0;
}

int selectionSort(int arr[], int len) {
	int min,i,j,temp;

	for (i = 0; i < len - 1; i++) {

		min = i;
		for (j = i+1; j < len; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		if (min != i) {
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	return 0;
}

int insertionSort(int arr[], int len) {
	int i,j,temp;

	for (i = 1; i < len; i++) {
		temp = arr[i];
		for (j = i; j > 0 && arr[j-1] > temp; j--) {
			arr[j] = arr[j-1];
		}
		arr[j] = temp;
	}

	return 0;
}

//希尔排序是基于插入排序
int shellSort(int arr[], int len) {

    int i,j,step,temp;

    for (step = len / 2; step >= 1; step /= 2) {
        for (i = step; i < len; i++) {
            temp = arr[i];
            j = i - step;
            while (j >= 0 && arr[j] > temp) {
                arr[j + step] = arr[j];
                j -= step;
            }
            arr[j + step] = temp;
        }
    }
	return 0;
}

int quickSort(int arr[], int start, int end) {
	int i,j,pivot,temp;

	if (start < end) {
		pivot = start;
		i = start;
		j = end;

		while (i < j) {
			while (arr[i] <= arr[pivot] && i < end) {
				i++;
			}
			while (arr[j] > arr[pivot]) {
				j--;
			}
			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[j];
		arr[j] = arr[pivot];
		arr[pivot] = temp;

		quickSort(arr, start, j-1);
		quickSort(arr, j+1, end);
	}

	return 0;
}

int main() {
	int len;
	int arr[] = {6,10,11,1,3,7,2,4,9,5,8};
	len = sizeof(arr) / sizeof(int);

	shellSort(arr, len);

	for (int i = 0; i<len; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");

	return 0;
}
