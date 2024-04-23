#include "Student_info.h"


#include <vector>
#include <iostream>
#include <vector>

std::istream& read(std::istream& is, Student_info& s) {
    // read and store the students name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}


// we must must pass the lvaule argument if we expect the function to change the value of the variable (vector)
// lvalue is non temporary object refernce parameter.
std::istream& read_hw(std::istream& in, std::vector<double>& hw) {
    if (in) {
        // get rid of privious content
        hw.clear();
        // read homework
        double x;
        while (in >> x) {
            hw.push_back(x);
        }
        // clear inputstream for endof file or badinput
        in.clear();
    }
    return in;
}

bool compare_student(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

