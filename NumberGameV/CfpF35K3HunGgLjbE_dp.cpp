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
    // { 1, 0 },
    // { 2, 1 },
    // { 3, 0 },
    // { 4, 1 },
    // { 6, 1 },
    // { 7, 0 },
};

//////////////////////
// start CodeFights //
//////////////////////

int NumberGameV (int n) {
    int maxMove;
    std::vector<int> dp(n+1, 0);
    for (int i=2; i<=n; ++i) {
        maxMove = -1;
        for (int move=i-1; move>0; --move) {
            if (
                dp[i-move] == 0 &&
                i % move == 0
            ) {
                maxMove = move;
                dp[i] = 1;
                break;
            }
        }
    }
    cout << "n = " << n << ", " << maxMove << endl;
    return dp[n];
}

////////////////////
// end CodeFights //
////////////////////

int main(int argc, char *argv[]) {

    for (int i=1; i< 500; ++i) {
        NumberGameV(i);
    }

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
