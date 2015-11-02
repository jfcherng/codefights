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

std::map<std::string, long> testcases = {
    { "6", 5 },
    { "391287046550400", 1230188 },
    { "4503599627370495", 1094 },
    { "4503599627370497", 14 },
    { "4503599627370449", 2 },
};

//////////////////////
// start CodeFights //
//////////////////////

#define L long long

// let X=N+R and Y=N+S, and it gives us R*S=N*N
// each (R, S) is one solution
// so we are going to count there are how many factors of N*N
// let r = numbers of factors of N*N
// because of symmetry, we should return (r+1)/2
L Solution_count (std::string N) {
    L r = 1;
    L n = stoll(N);

    for (L i=3; i*i<=n; ++i) {
        L e = 0;
        while (n % i == 0) {
            ++e;
            n /= i;
        }
        if (e > 0) {
            r *= 2*e+1; // i^0, i^1, ..., i^(2*e)
            cout << i << " ^ " << e << endl;
        }
    }


    // evil CuongVM, he must put some large prime numbers in test cases
    if (n != 1) {
        r *= 3; // there is a LARGE prime number left
        cout << n << " ^ " << 1 << endl;
    }

    return r/2 + 1;
}

////////////
// end CodeFights //
////////////////////

int main(int argc, char *argv[]) {

    // cout << Solution_count("1000");

    for (auto && kv : testcases) {
        auto result = Solution_count(kv.first);
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
