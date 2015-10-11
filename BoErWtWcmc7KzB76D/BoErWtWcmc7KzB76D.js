function Untold(T0, T1, Numbers, n) {
    M = Numbers[5];
    T = [T0%M, T1%M];
    m = { };
    m[map(T)] = 0;
    for (i=2; i<=n; ++i) {
        T.push((
            Numbers[0]*T[i-2]*T[i-2] +
            Numbers[1]*T[i-1]*T[i-1] +
            Numbers[2]*T[i-2] +
            Numbers[3]*T[i-1] +
            Numbers[4]
        ) % M);
        k = map(T.slice(-2));
        p = i-1-m[k];
        if (k in m) {
            return T[(n-i+1)%p + m[k]];
        } else {
            m[k] = i-1;
        }
    }
    return T[n];
}

function map (a) {
    return a.join(',');
}
