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

std::map<std::vector<std::string>, std::vector<int>> testcases = {
    { {"00:00:00", "00:00:00"}, {6,0,0,0,0,0,0,0,0,0} } ,
    { {"23:59:58", "23:59:59"}, {0,0,2,2,0,4,0,0,1,3} } ,
};

//////////////////////
// start CodeFights //
//////////////////////

class Timer {
private:
    int time;

public:
    Timer (const std::string &t) : time(0) {
        int h, m, s;
        sscanf(t.c_str(), "%d:%d:%d", &h, &m, &s);
        this->time = h*3600 + m*60 + s;
    }
    bool operator<= (const Timer &a) const {
        return this->time <= a.time;
    }
    Timer &operator++ () {
        ++this->time;
        return *this;
    }
    // HHMMSS
    std::string getStringFormat () const {
        int h, m, s = this->time;
        h = s/3600; s -= h*3600;
        m = s/60;   s -= m*60;
        char c[7];
        sprintf(c, "%02d%02d%02d", h, m, s);
        return c;
    }
};

std::vector<int> digit_hours (std::string period_from, std::string period_to) {
    std::vector<int> ans(10);
    Timer from(period_from), to(period_to);
    while (from <= to) {
        for (auto c : from.getStringFormat())
            ++ans[c-'0'];
        ++from;
    }
    return ans;
}

////////////////////
// end CodeFights //
////////////////////

int main(int argc, char *argv[]) {

    for (auto && e : testcases) {
        auto result = digit_hours(e.first[0], e.first[1]);
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
