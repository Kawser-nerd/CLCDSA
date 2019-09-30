def solve(S):
    C = S
    N = len(S)

    if C[0] == '0':
        cnt = 1
        while cnt < N and C[cnt] == '0':
            cnt += 1
        C = C[cnt:]
        a = 10**cnt
    else:
        cnt = 1
        while cnt < N and C[cnt] == '0':
            cnt += 1
        a = int(C[:cnt])
        C = C[cnt:]

    L = len(C)
    d = 1
    if C:
        d = int(C) - a
        b = int(C[0])
        p = 1
        while p < L and (b <= a or C[p] == '0'):
            b = b*10 + int(C[p])
            p += 1
        if p == L:
            numl = numr = b
            while numr <= a:
                numl *= 10
                numr = numr*10 + 9
            d = max(numl-a, 1)
        for i in range(p, L):
            if C[i] == '0':
                b = b*10 + int(C[i])
                continue
            d0 = b - a
            nxt = a+d0+d0
            numl = numr = 0
            j = i
            while j < L or 0 < numr < nxt:
                if L <= j:
                    numl = 10*numl
                    numr = 10*numr + 9
                else:
                    numl = 10*numl + int(C[j])
                    numr = 10*numr + int(C[j])
                if numl <= nxt <= numr and (L <= j+1 or C[j+1] != '0'):
                    numl = numr = 0
                    nxt += d0
                j += 1
            if numr == 0:
                d = d0
                break
            b = b*10 + int(C[i])
    #print(a, d)
    s = ""
    f = a + d
    while len(s) < L:
        s += str(f)
        f += d
    assert str(a)[L-N:] + s[:L] == S

    return a, d
print(*solve(input()))