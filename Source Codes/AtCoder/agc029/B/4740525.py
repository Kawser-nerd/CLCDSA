from collections import Counter

# ??
N = int(input())
A = list(map(int, input().split()))

# ???????????????????????????????
C = Counter(A)
ans = 0
for m in sorted(C, reverse=True):
    p = (1 << m.bit_length()) - m
    if m == p:
        ans += C[m] // 2
    elif p in C:
        k = min(C[m], C[p])
        ans += k
        C[p] -= k

# ??
print(ans)