#include "median.h"
#include <vector>
#include <stdexcept>
#include <algorithm>

//  median function copies vector to vec when calling functino since we are sorting values of vector it makes sences that function should not change the orignal vector for finding median.
double median(std::vector<double> vec) {
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw std::domain_error("Median of an empty array");
    }
    std::sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid + 1]) / 2 : vec[mid];
}
