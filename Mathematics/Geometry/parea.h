#pragma once
#ifndef PAREA_H
#define PAREA_H
#include<vector>
struct point {
	double x;
	double y;
};
double area(const std::vector<point>& vp);
#endif