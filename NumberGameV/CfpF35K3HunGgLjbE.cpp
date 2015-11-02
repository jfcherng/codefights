#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <cstdio>

using namespace std;

///////////////
// utilities //
///////////////

// std::cout for a vector
template <class T>
std::ostream &operator<< (std::ostream &out, const std::vector<T> &v) {
    out << '[';
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    if (!v.empty()) out << "\b\b";
    out << "]";
    return out;
}

///////////////
// testcases //
///////////////

std::map<int, int> testcases = {
    { 1, -1 },
    { 2,  1 },
    { 3, -1 },
    { 4,  1 },
    { 5, -1 },
    { 6,  3 },
    { 7, -1 },
};

//////////////////////
// start CodeFights //
//////////////////////

int NumberGameV (int n) {
    // `n&-n` gives the max factor, which is power of 2, of `n`
    return n&1 ? -1 : n/(n&-n);
}

////////////////////
// end CodeFights //
////////////////////

int main(int argc, char *argv[]) {

    for (auto && kv : testcases) {
        auto result = NumberGameV(kv.first);
        if (result != kv.second) {
            std::cout << "error: " << kv.first
                      << " should be " << kv.second
                      << " but " << result
                      << std::endl;
            break;
        }
    }
    std::cout << "DONE" << std::endl;

    return 0;
}
