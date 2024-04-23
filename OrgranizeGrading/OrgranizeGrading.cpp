// OrgranizeGrading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include "grade.h"

using namespace std;

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
    sort(students.begin(), students.end(), compare_student );
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

