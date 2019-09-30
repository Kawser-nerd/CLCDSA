mod = 1000000007

S = input()
n = 1
a = 0
ab = 0
abc = 0
for s in S:
    if s in "A":
        a += n
    if s in "B":
        ab += a
    if s == "C":
        abc += ab
    if s in "?":
        n, a, ab, abc = 3 * n, 3 * a + n, 3 * ab + a, 3 * abc + ab
    n %= mod
    a %= mod
    ab %= mod
    abc %= mod

print(abc % mod)