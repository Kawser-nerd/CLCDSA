from pylab import *

digs = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

A = zeros((26, 10))
for d in range(10):
    for c in digs[d]:
        A[ord(c) - ord('A')][d] += 1

T = int(input())
for t in range(T):
    s = input().strip()
    freks = zeros(26)
    for c in s:
        freks[ord(c) - ord('A')] += 1
    ans = ''
    sol = lstsq(A, freks)[0]
    for i in range(10):
        x = round(sol[i])
        ans += chr(ord('0') + i) * x

    print("Case #{}: {}".format(t+1, ans))
