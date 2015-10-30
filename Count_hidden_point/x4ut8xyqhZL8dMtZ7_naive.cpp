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

std::map<int, std::string> testcases = {
    { 5, "30" },
    { 10, "138" },
    { 1000, "1177848" },
};

//////////////////////
// start CodeFights //
//////////////////////

std::string Count_hiden_point(int N) {
    int cnt = 0;
    // polar coordinates
    for (int r=2; r<=N; ++r) {
        ++cnt; // theta=0 always counts
        for (int theta=1; theta<r; ++theta) {
            if (std::__gcd(r, theta) != 1) {
                ++cnt;
            }
        }
    }
    return std::to_string(cnt*6);
}

////////////////////
// end CodeFights //
////////////////////

int main(int argc, char *argv[]) {

    for (auto && kv : testcases) {
        auto result = Count_hiden_point(kv.first);
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
