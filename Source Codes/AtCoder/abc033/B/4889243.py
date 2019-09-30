N = int(input())
S = []
P = []

for i in range(N):
    s, p = input().split()
    S.append(s)
    P.append(int(p))

if max(P) > sum(P)/2:
    print(S[P.index(max(P))])
else:
    print("atcoder")