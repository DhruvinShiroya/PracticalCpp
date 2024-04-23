#include "grade.h"
#include "median.h"
#include "Student_info.h"
// this midterm , final , homework is call by value when we call this function it copies the argumnet for fucntion and when function return it destroys created arguments.
#include <vector>
#include <stdexcept>

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector<double>& hw ){
    if (hw.size() == 0) {
        throw std::domain_error("Student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}
