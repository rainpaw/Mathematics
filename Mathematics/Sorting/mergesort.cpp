#include <iostream>
#include "header file/mergesort.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
int main() {
	int n;
	cout << "Enter the no. of elements ";
	cin >> n;
	int* a = new int[n];
	cout << "Enter the elements in any order";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	auto start = high_resolution_clock::now();
	mergesort(a, n);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	cout << "The sorted array is :";
	for (int i = 0; i < n; i++) {
		cout << a[i] <<" ";
	}
	cout << "time taken " << duration.count() << "ns";

	delete[]a;
}