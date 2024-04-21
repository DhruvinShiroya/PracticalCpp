// OrgranizeGrading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using namespace std;

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};


// this midter , final , homework is call by value when we call this function it copies the argumnet for fucntion and when function return it destroys created arguments.
double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

//  median function copies vector to vec when calling functino since we are sorting values of vector it makes sences that function should not change the orignal vector for finding median.
double median(vector<double> vec) {
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size = 0) {
        throw domain_error("Median of an empty array");
    }
    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid + 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0) {
        throw domain_error("Student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

// we must must pass the lvaule argument if we expect the function to change the valeu of the variable (vector)
// lvalue is non temporary object refernce parameter.
istream& read_hw(istream& in, vector<double>& hw) {
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

istream& read(istream& is, Student_info& s) {
    // read and store the students name and mmidterm and final exam grades
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}

double grade(Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

bool compare_student(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}


int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store the record and find the length of longest name
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    //sort the students by name
    sort(students.begin(), students.end(), compare_student);
    
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        // write name with correct padding for final grade
        cout << students[i].name << string((maxlen + 1) - students[i].name.size(), ' ');

        // compute and print grade
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(4) << final_grade << setprecision(prec) ;
        }
        catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
   return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

