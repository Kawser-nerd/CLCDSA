from fractions import gcd
N,M = map(int,input().split())
S = input()
T = input()
g = gcd(N,M)
l = N*M//g

for i in range(g):
    if S[N*i//g] != T[M*i//g]:
        print(-1)
        exit()
print(l)