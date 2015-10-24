#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <bitset>

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

std::map<std::vector<int>, int> testcases = {
    { {7, 4}, 2 } ,
    { {7, 1}, 7 } ,
    { {1, 7}, 1 } ,
};

//////////////////////
// start CodeFights //
//////////////////////

/**
 * Consider solving TheLastStone(7, 4).
 * At first, we have [1, 2, 3, 4, 5, 6, 7] in a ring.
 * After the 1st kill, we have [5, 6, 7, 1, 2, 3].
 *
 * Consider TheLastStone(6, 4),
 * [1, 2, 3, 4, 5, 6] can be mapped to [5, 6, 7, 1, 2, 3] by performing (X+3)%7+1
 * That yields TheLastStone(7, 4) = (TheLastStone(6, 4)+3)%7+1
 *             ..................
 *             TheLastStone(2, 4) = (TheLastStone(1, 4)+3)%2+1
 *             TheLastStone(1, 4) = 1
 *
 * It's not to hard to find following relationships.
 * { TheLastStone(n, p) = (TheLastStone(n-1, p)+(p-1))%n+1
 * { TheLastStone(1, p) = 1
 *
 */
int TheLastStone (int n, int p) {
    return n==1 ? 1 : (TheLastStone(n-1, p)+(p-1))%n+1;
}

////////////////////
// end CodeFights //
////////////////////


int main(int argc, char *argv[]) {

    for (auto && e : testcases) {
        auto result = TheLastStone(e.first[0], e.first[1]);
        if (result != e.second) {
            std::cout << "error: " << e.first[0] << "," << e.first[1]
                      << " should be " << e.second
                      << " but " << result
                      << std::endl;
            break;
        }
    }
    std::cout << "DONE" << std::endl;

    return 0;
}
