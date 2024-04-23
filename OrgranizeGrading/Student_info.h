#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <vector>
#include <string>
#include <iostream>
struct Student_info {
    std::string name;
    double midterm, final ;
    std::vector<double> homework;
};

bool compare_student(const Student_info& , const Student_info& );
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream& , std::vector<double>& );

#endif // !



