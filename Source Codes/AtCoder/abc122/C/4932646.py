N, Q = [int(x) for x in input().split()]
S = input()

t = [0] * (N + 1)

for i in range(N):
    if S[i:i+2] == 'AC':
        t[i+1] = t[i] + 1
    else:
        t[i+1] = t[i]

for i in range(Q):
    l, r = [int(x) for x in input().split()]
    print(t[r-1] - t[l-1])