def Untold(T0, T1, Numbers, n):
    a, b, x, y, z, M = Numbers
    T = [T0, T1]
    m = { (T0,T1) : 0 }
    i = 2
    while i <= n:
        T.append((a*T[-2]**2 + b*T[-1]**2 + x*T[-2] + y*T[-1] + z) % M)
        k = (T[-2], T[-1])
        try:
            p = i-1-m[k]
            return T[(n-i+1)%p + m[k]]
        except:
            m[k] = i-1
        i += 1
    return T[n] % M
