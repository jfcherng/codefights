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

#define L long

std::vector<int> primes;

// hopefully it's name explains itself
bool isPrime (L n) {
    for (L i=2; i*i<=n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

// Euler's totient function
L phi (L n) {
    L r = 1;
    // all primes <= `n` need to be in `primes` already
    for (L p : primes) {
        if (p > n) break;
        L e = 0;
        while (n % p == 0) ++e, n /= p;
        if (e > 0) r *= pow(p, e-1)*(p-1);
    }
    return r;
}

std::string Count_hiden_point(int N) {
    L cnt = 0;
    // generate all primes <= `N`
    for (L i=2; i<=N; ++i) {
        if (isPrime(i))
            primes.push_back(i);
        // hidden points on a side of hexagonal whose side length is `i`
        cnt += i-phi(i);
    }
    // hexagonal
    cnt *= 6;
    return std::to_string(cnt);
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
