function RomanExpression(expression) {
    return parseInt(eval(expression.replace(/[\w=]+/g, function (roman) {
        map = {
            M    : 1000,
            D    : 500 ,
            C    : 100 ,
            L    : 50  ,
            X    : 10  ,
            V    : 5   ,
            I    : 1   ,
            '='  : 0
        };
        arabic = prev = 0;
        i = roman.length;
        while (i--) {
            next = m[roman[i]];
            arabic += next<prev ? -next : next;
            prev = next;
        }
        return arabic;
    })));
}
