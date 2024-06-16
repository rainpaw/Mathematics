#pragma once
#ifndef QUICKSORT_H
#define QUICKSORT_H
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int partition(int* a, int l, int r) {
    int p = a[l];
    int i = l + 1; 
    int j = r;
    while (i <= j) {
        while (i <= j && a[i] <= p) {
            i++;
        }
        while (i <= j && a[j] > p) { 
            j--;
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void quicksort(int* a, int l, int r) {
	if (l >= r) return;
	int s = partition(a, l, r);
	quicksort(a, l, s - 1);
	quicksort(a, s+1, r);
}
#endif