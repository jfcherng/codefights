#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

///////////////
// utilities //
///////////////

// std::cout for a vector
template <class T>
std::ostream &operator<< (std::ostream &out, std::vector<T> &v) {
    out << '[';
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    if (!v.empty()) out << "\b\b";
    out << "]";
    return out;
}

///////////////
// testcases //
///////////////

std::map<std::string, long long> testcases = {
    { "10" , 55   },
    { "100", 3728 },
};

//////////////////////
// start CodeFights //
//////////////////////

#define L long long

std::vector<L> primes;

// hopefully the function name explains itself
bool isPrime (L n) {
    for (L i=2; i*i<=n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

// We are going to build a tree using "primes".
// Every prime in "primes" can only appear once except 2, 3, 5.
// The product of a path should not exceed the "n" of its starting node.
L dfs_recursive (L maxIdx, L n, L edgeWeighting) {
    // the sum of children for current node
    L sum = 0;
    // visit all children
    for (L idx=0; idx<=maxIdx; ++idx) {
        L p = primes[idx];
        // because "primes" is sorted in ascending order,
        // the rest of primes must be even larger then "p"
        // we can perform a early break here
        if (p > n) break;
        // now we go into a deeper child
        // occurrence for 2, 3, 5 are unlimited
        // so no decrement if "p" is one of them
        sum += p + dfs_recursive(idx-(p>5), n/p, p);
    }
    // all children have been visited, backtrace to the parent
    return sum * edgeWeighting;
}

// This is an iterative version of dfs_recursive(...)
L dfs_iterative (L maxIdx, L n, L pathProduct) {
    typedef struct { L maxIdx, n, pathProduct; } node;
    std::stack<node> s;
    L sum = 0;
    s.push({ maxIdx, n, 1 });
    while (!s.empty()) {
        node t = s.top();
        s.pop();
        for (L idx=0; idx<=t.maxIdx; ++idx) {
            L p = primes[idx];
            if (p > t.n) break;
            s.push({ idx-(p>5), t.n/p, p*t.pathProduct });
        }
        sum += t.pathProduct;
    }
    return sum - 1;
}

L Hamming_number_part3 (std::string N) {
    L n = stoll(N);
    // find primes that are allowed to be a factor of phi(N)
    // i.e., primes that are in the form of 2^i * 3^j * 5^k +1
    for (L i=1; i<n; i*=2) {
        for (L j=1; i*j<n; j*=3) {
            for (L k=1; i*j*k<n; k*=5) {
                L number = i*j*k + 1;
                if (isPrime(number))
                    primes.push_back(number);
            }
        }
    }
    // we sort those primes in ascending order
    // so our algorithm can run faster in the later progress
    std::sort(std::begin(primes), std::end(primes));
    // "&& ((L)1<<32)-1" can be used to do mod 2^32 if you want
    // "1" is not in our prime list thus we add it into our sum manually
    return 1 + dfs_recursive(primes.size()-1, n, 1);
}

////////////////////
// end CodeFights //
////////////////////

int main(int argc, char *argv[]) {

    for (auto && kv : testcases) {

        // reset global variables
        primes = {};

        auto result = Hamming_number_part3(kv.first);
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
