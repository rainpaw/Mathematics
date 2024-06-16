#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
bool isprimebf(int n) {
	if (n == 0 || n == 1) {
		return false;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
bool isprimemat(int n) {
	if (n == 0 || n == 1) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	cout << "Enter the number to test for prime";
	cin >> n;
	auto start = high_resolution_clock::now();
	bool m = isprimebf(n);
	cout << std::boolalpha << m;
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	cout << "Time Taken by bf " << duration.count() <<endl;
	auto start2 = high_resolution_clock::now();
	bool k = isprimemat(n);
	cout << std::boolalpha << k;
	auto end2 = high_resolution_clock::now();
	auto dr = duration_cast<milliseconds>(end2 - start2);
	cout << "time take by math prime" << dr.count()<<endl;
}