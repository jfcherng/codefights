#define S std::string
#define d double
#define c char
#define b return
#define w while
#define y *i
#define z y++

c y;

d F() {
    w (y < 33) z;
    d r = 0, p = 0, n;
    if (y > 64) {
        c *s = i;
        w (y > 64) z;
        c *e = i;
        w (e-- - s)
            n = (int) pow(10, 205558 % *e % 7) % 9995,
            r += n<p ? -n : n,
            p = n;
        b r;
    }
    b y<41 ? z, r = E(), z, r : y>43 ? z, -F() : 0;
}
d T() {
    d r = F();
    w (y==42 || y==47)
        r *= z-42 ? 1/F() : F();
    b r;
}
d E() {
    d r = T();
    w (abs(y-44) < 2)
        r -= (z-44) * T();
    b r;
}
d RomanExpression(S e) {
    i = &e[0];
    b E();
}
