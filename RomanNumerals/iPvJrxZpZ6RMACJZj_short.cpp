#define S std::string
#define W while
#define R return
#define c char
#define Q(E) t = 0;    W (Z C) ++i, ++t;    R t < E
#define Z *i==

c *i, *e;
int t, a=0, p=0;

c V(c D, c C, c M) {
    if (Z D) {
        ++i;
        Q(4);
    }
    if (Z C) {
        ++i;
        if (Z C) {
            Q(3);
        }
        if (Z M | Z D)
            ++i;
    }
    R 1;
}

int RomanNumerals(S s) {
    i = e = &s[0] + s.size();

    W (i-- != &s[0])
        t = pow(10, 205558 % *i % 7),
        t %= 9995,
        a += t < p ? -t : t,
        p = t;

    do
        ++i;
    W (Z 77);

    R
        V(68, 67, 77) &
        V(76, 88, 67) &
        V(86, 73, 88) &
        i == e

        ? a : -1;
}
