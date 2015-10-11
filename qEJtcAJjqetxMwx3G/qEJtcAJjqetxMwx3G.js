function RomanExpression(E) {
    return parseInt(eval(E.replace(/[A-Z=]+/g, function (R) {
        m = {
            M    : 1000,
            D    : 500 ,
            C    : 100 ,
            L    : 50  ,
            X    : 10  ,
            V    : 5   ,
            I    : 1   ,
            '='  : 0
        };
        A = p = 0;
        i = R.length;
        while (i--) {
            n = m[R[i]];
            A += n<p ? -n : n;
            p = n;
        }
        return A;
    })))
}
