t = int(input())

def inverse(s):
    return "".join(chr(ord(u) ^ 1) for u in s)

def chapeau(s):
    if len(s) == 0:
        return ""
    u = 0
    while u < len(s) and s[u] == s[0]:
        u += 1
    if u == len(s):
        return s[0] * (u - 1)
    rem = s[u:]
    return s[0] * (u - 1) + inverse(s[0]) + s[0] + chapeau(rem)
 
for i in range(t):
    print("Case #%d:" % (i + 1), end = " ")
    n, l = map(int, input().split())
    good = input().strip().split()
    bad = input().strip()
    if bad in good:
        print("IMPOSSIBLE")
    else:
        if l == 1:
            print(inverse(bad[0]) + "? " + inverse(bad[0]))
            continue
        z = inverse(bad)
        u = chapeau(bad)
        v = "".join(c + "?" for c in z)
        assert (len(u) + len(v) <= 200)
        print(u + " " + v)
