import math

N, M = map(int, input().split())
ans=0
inf=(10**9)+7
if abs(N-M)==0:
    ans=2*math.factorial(N)*math.factorial(M)
elif abs(N-M)==1:
    ans=math.factorial(N)*math.factorial(M)
else:
    ans=0
print(ans%inf)