#include <iostream>
#include <string>
#include <map>

std::map<std::string, int> testcases = {
    { "V+V=", 10 },
    { "IX=", 9 },
    { "(III+VI)*CM=", 8100 },
    { " V = ", 5 },
};

double expression();

//////////////////////
// start codefights //
//////////////////////

char *exprIter;

std::map<char, int> m = {
    { 'M' , 1000 } ,
    { 'D' , 500  } ,
    { 'C' , 100  } ,
    { 'L' , 50   } ,
    { 'X' , 10   } ,
    { 'V' , 5    } ,
    { 'I' , 1    } ,
};

char peek() {
    return *exprIter;
}

char get() {
    return *exprIter++;
}

bool isRoman(char c) {
    return std::string("IVXLCDM").find(c) != std::string::npos;
}

int romanToArabic(char *st, char *ed) {
    int sum = 0, prev = 0, next;
    while (ed-- != st) {
        next = m[*ed];
        sum += next < prev ? -next : next;
        prev = next;
    }
    return sum;
}

// LL(1) parser

int roman() {
    char *st = exprIter;
    while (isRoman(peek())) {
        get();
    }
    return romanToArabic(st, exprIter);
}

int factor() {
    while (peek() == ' ') {
        get();
    }
    if (isRoman(peek())) {
        return roman();
    } else if (peek() == '(') {
        get(); // '('
        double result = expression();
        get(); // ')'
        return result;
    } else if (peek() == '-') {
        get();
        return -factor();
    }
    return 0; // exception: '='
}

double term() {
    double result = factor();
    while (peek() == '*' || peek() == '/') {
        if (get() == '*') {
            result *= factor();
        } else {
            result /= factor();
        }
    }
    return result;
}

double expression() {
    double result = term();
    while (peek() == '+' || peek() == '-') {
        if (get() == '+') {
            result += factor();
        } else {
            result -= factor();
        }
    }
    return result;
}

int RomanExpression(std::string e) {
    exprIter = &e[0];
    return expression();
}

////////////////////
// end codefights //
////////////////////

int main() {
    std::string expr;
    double result;
    for (auto &&kv : testcases) {
        result = RomanExpression(kv.first);
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
