N,M = map(int, input().split())
S = input()
T = input()
from fractions import gcd

# 15, 9
# 3$BJ8;z$:$D8+$F$$$/!"(B5$BJ8;z$:$D8+$F$$$/(B
LEN = N*M // gcd(N,M) # 45
p = LEN // N # 3
q = LEN // M # 5
lcm = p*q//gcd(p,q)

for i in range(0, LEN//lcm):
    if S[i*q] != T[i*p]:
        print(-1)
        exit()
print(LEN)