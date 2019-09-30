import sys

s2nn = lambda s: [int(c) for c in s.split(' ')]

ss2nn = lambda ss: [int(s) for s in list(ss)]
ss2nnn = lambda ss: [s2nn(s) for s in list(ss)]

i2s = lambda: sys.stdin.readline().rstrip()
i2n = lambda: int(i2s())
i2nn = lambda: s2nn(i2s())

ii2ss = lambda n: [sys.stdin.readline() for _ in range(n)]

def main(N, Q, S, lrs):
    S2 = [0] * (N)
    for i in range(1, N):
        if S[i-1] == 'A' and S[i] == 'C':
            S2[i] = S2[i-1] + 1
        else:
            S2[i] = S2[i-1]
    for l, r in lrs:
        count = S2[r-1] - S2[l-1] 
        print(count)

N, Q = i2nn()
S = i2s()
lr = ss2nnn(ii2ss(Q))
main(N, Q, S, lr)