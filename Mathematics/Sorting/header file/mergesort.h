#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H
#include <cmath>
void merge(int* b,int p, int* c,int q, int* a,int n) {
	int i = 0, j = 0, k = 0;
	while (i < p && j < q) {
		if (b[i] < c[j]) {
			a[k] = b[i]; i++;
		}
		else {
			a[k] = c[j]; j++;
		}
		k++;
	}
	while (i < p) {
		a[k] = b[i]; i++;
		k++;
	}
	while (j < q) {
		a[k] = c[j]; j++;
		k++;
	}
}
void mergesort(int* a, int n) {
	if (n <= 1) return;

	int m = floor(n / 2);
	int k = n - m;
	int* b = new int[m];
	int* c = new int[k];
	for (int i = 0; i < m; i++) {
		b[i] = a[i];
	}
	for (int j = 0; j < k; j++) {
		c[j] = a[m+j];
	}

	mergesort(b, m);
	mergesort(c, k);
	merge(b, m, c, k, a, n);
	delete[]b;
	delete[]c;
	
}
#endif