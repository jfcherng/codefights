#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

template <class S, class V>
S Tourney(int N, V n, S F) {
    int s = N+1>>1, i = 0;
    while (i+s < N)
        n[i++] = F + "(" + n[i] + "," + n[i+s] + ")";
    return N^1        ? Tourney(s, n, F) :
           n.size()^1 ? n[0] :
                        F + "(" + n[0] + ")";
}

void verify (int N, string F) {
    vector<string> n;
    for (int i=0; i<N; ++i) n.push_back(to_string(i+1));
    cout << "N = " << setw(2) << N << " : "
         << Tourney(N, n, F)
         << endl;
}

int main(int argc, char *argv[]) {
    for (int i=1; i<=32; ++i) verify(i, "");
    cout << "DONE" << endl;
    return 0;
}
