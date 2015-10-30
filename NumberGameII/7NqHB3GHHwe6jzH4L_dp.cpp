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

std::map<int, bool> testcases = {
    { 1, 0 },
    { 6, 0 },
    { 7, 1 },
};

//////////////////////
// start CodeFights //
//////////////////////

bool NumberGameII (int n) {
    std::vector<int> dp(n+1, 0);
    for (int i=2; i<=n; ++i) {
        int move = log2(i);
        auto e = begin(dp)+i;
        dp[i] = find(e-move, e, 0) != e;
    }
    return dp[n];
}

////////////////////
// end CodeFights //
////////////////////

int main(int argc, char *argv[]) {

    for (auto && kv : testcases) {
        auto result = NumberGameII(kv.first);
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
