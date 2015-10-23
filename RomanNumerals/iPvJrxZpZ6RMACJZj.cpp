#include <map>
#include <string>
#include <iostream>

std::map<std::string, int> testcases = {
    { "VV"    , -1   } ,
    { "DD"    , -1   } ,
    { "LL"    , -1   } ,
    { "MICXV" , -1   } ,
    //
    { "MXV"   , 1015 } ,
    { "XIV"   , 14   } ,
    //
    { "M"     , 1000 } ,
    { "D"     , 500  } ,
    { "C"     , 100  } ,
    { "L"     , 50   } ,
    { "X"     , 10   } ,
    { "V"     , 5    } ,
    { "I"     , 1    } ,
};

//////////////////////
// start codefights //
//////////////////////

char *i, *ed;

std::map<char, int> romanCharMap = {
    { 'M' , 1000 } ,
    { 'D' , 500  } ,
    { 'C' , 100  } ,
    { 'L' , 50   } ,
    { 'X' , 10   } ,
    { 'V' , 5    } ,
    { 'I' , 1    } ,
};

// this function validates this regex: D?C{0,3}|C[MD]
bool validateRomanSegment(char D, char C, char M) {
    int cnt = 0;
    // D
    if (*i == D) {
        ++i;
        // C{0,3}
        while (*i == C) {
            ++i;
            ++cnt;
        }
        return cnt < 4;
    }
    // C
    if (*i == C) {
        ++i;
        // C{0,2}
        if (*i == C) {
            while (*i == C) {
                ++i;
                ++cnt;
            }
            return cnt < 3;
        }
        // [MD]
        if (*i == M || *i == D) {
            ++i;
        }
    }
    return true;
}

// this function tests a string with the following regex to validate Romans
// ^M*(D?C{0,3}|C[MD])(L?X{0,3}|X[CL])(V?I{0,3}|I[XV])$
bool validateRoman(std::string s) {
    while (*i == 'M') ++i; // ^M*
    return
        validateRomanSegment('D', 'C', 'M') && // (D?C{0,3}|C[MD])
        validateRomanSegment('L', 'X', 'C') && // (L?X{0,3}|X[CL])
        validateRomanSegment('V', 'I', 'X') && // (V?I{0,3}|I[XV])
        i == ed; // $
}

int RomanNumerals(std::string s) {
    i = &s[0];
    ed = i + s.size();

    if (!validateRoman(s)) return -1;

    // evaluate Romans
    int sum = 0, prev = 0, next;
    while (ed-- != &s[0]) {
        next = romanCharMap[*ed];
        sum += next < prev ? -next : next;
        prev = next;
    }
    return sum;
}

////////////////////
// end codefights //
////////////////////

int main() {
    int result;
    for (auto &&kv : testcases) {
        result = RomanNumerals(kv.first);
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
