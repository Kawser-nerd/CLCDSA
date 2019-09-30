n,m = map(int,input().split())
def seprate(string):
    return int(string)%m
A = list(map(seprate,input().split()))

S = [0]*n
sm = 0
ans = 0
import math
def Comb(a,b):#aCb???
    if a>= b:
        return int(math.factorial(a)/(math.factorial(b)*math.factorial(a-b)))
    else:
        return 0

for a,i in zip(A,range(n)):
    sm = (sm+a)%m
    S[i] += sm
S.sort()
temp= S[0]
c = 1
zeros = 1 if temp == 0 else 0
for s in S[1:]:
    if s == 0:
        zeros += 1
        c += 1
    elif temp == s:
        c += 1
    else:
        ans += Comb(c,2)
        c = 1
    temp = s
ans += Comb(c,2)+zeros
print(ans)