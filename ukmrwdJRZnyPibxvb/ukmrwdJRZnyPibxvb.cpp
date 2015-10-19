#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

std::string Tourney(int N, std::vector<std::string> n, std::string F) {
    int step = (N+1) / 2;
    for (int i=0; i+step<N; ++i)
        n[i] = F + "(" + n[i] + "," + n[i+step] + ")";
    if (N != 1) return Tourney(step, n, F);
    if (n.size() != 1) return n[0];
    return F + "(" + n[0] + ")";
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
