typedef std::vector<int> v;

void f (v &T, v &N, int i) {
    T.push_back((
        N[0]*(T[i-2]*T[i-2] % N[5]) +
        N[1]*(T[i-1]*T[i-1] % N[5]) +
        N[2]*T[i-2] +
        N[3]*T[i-1] +
        N[4]
    ) % N[5]);
}

int h (int a, int b) {
    return (a+b) * (a+b+1) / 2 + b;
}

int Untold (int T0, int T1, v Numbers, int n) {
    std::map<int, int> m;
    int M = Numbers[5], i, k, p;
    T0 %= M;
    T1 %= M;
    v T = { T0, T1 };
    m[h(T0, T1)] = 0;
    for (i=2; i<=n; ++i) {
        f(T, Numbers, i);
        k = h(T[T.size()-2], T.back());
        if (m.count(k)) {
            p = i-1-m[k];
            return T[(n-i+1)%p + m[k]];
        } else
            m[k] = i-1;
    }
    return T[n];
}
