#ifndef GUARD_GRADE
#define GUARD_GRADE

#include "Student_info.h"
#include <vector>

double grade(const Student_info &s);
double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>&);

#endif
