N,M = map(int,input().split())
S = input()
T = input()
flag = True
def lcm(a, b): # ?????
    def gcd(a, b): # ?????
        while b:
            a, b = b, a % b
        return a
    return a * b // gcd(a, b)
L = lcm(N,M)
def gcd(a, b): # ?????
    while b:
        a, b = b, a % b
    return a

flag = True
for i in range(gcd(N,M)):
    if S[i*N//gcd(N,M)] == T[i*M//gcd(N,M)] and flag:
        pass
    else:
        flag = False
if flag:
    print(L)
else:
    print(-1)