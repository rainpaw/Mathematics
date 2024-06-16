#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(int b[], int c[], int ar[], int n) {
    int i = 0, j = 0, k = 0;
    int n2 = n / 2;

    while (i < n2 && j < n - n2) {
        if (b[i] < c[j]) {
            ar[k++] = b[i++];
        }
        else {
            ar[k++] = c[j++];
        }
    }

    while (i < n2) {
        ar[k++] = b[i++];
    }

    while (j < n - n2) {
        ar[k++] = c[j++];
    }
}

void mergesort(int ar[], int n) {
    if (n <= 1) return;

    int n2 = n / 2;
    int* b = new int[n2];
    int* c = new int[n - n2];

    for (int i = 0; i < n2; i++) {
        b[i] = ar[i];
    }
    for (int i = 0; i < n - n2; i++) {
        c[i] = ar[i + n2];
    }

    mergesort(b, n2);
    mergesort(c, n - n2);

    merge(b, c, ar, n);

    delete[] b;
    delete[] c;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* ar = new int[n];

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    auto start = high_resolution_clock::now();

    mergesort(ar, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;

    cout << "Time taken by mergesort: " << duration.count() << " milliseconds" << endl;

    delete[] ar;

    return 0;
}
