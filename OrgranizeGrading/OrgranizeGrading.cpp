// OrgranizeGrading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
using namespace std;

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



int main()
{
    // ask for and read student's name
    cout << "Please enter your first name;";
    string name;
    cin >> name;
    cout << "Hello, " << name << endl;

    // ask for and read the midter and final grades 
    cout << "Please enter your midterm and final grades: ";
    double midterm, final;
    cin >> midterm >> final;
    
    // ask for homework grades
    cout << "Enter all your homework grades, followedby end of file: ";
    vector<double> homework;

    read_hw(cin, homework);

    // compute and generate the final grade
    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
            << final_grade << setprecision(prec) << endl;
    }
    catch (domain_error) {
        cout << endl << "You must enter your grades . "
            "Please try again." << endl;
        return 1;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

