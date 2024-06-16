#include "parea.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
double area(const std::vector<point>& vp) {
	double ans = 0;
	for (unsigned i = 0; i < vp.size(); i++) {
		point p1 = i ? vp[i - 1] : vp.back(), p2 = vp[i];
		ans += (p2.x - p1.x) * (p2.y + p1.y);
	}
	return fabs(ans) / 2;
}
int main() {
	int n;
	cout << "Enter the no of vertices of polygon";
	cin >> n;
	vector<point> vp(n);
	cout << "Enter the vertices of polygon";
	for (auto i = 0; i < n; i++) {
		cout << "Vertex " << i + 1 << ": ";
		cin >> vp[i].x >> vp[i].y;
	}
	cout << "Area of polygin is : ";
	cout << area(vp);
}