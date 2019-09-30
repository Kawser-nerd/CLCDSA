import math
N=math.factorial(int(input()))
i=2
ans=1
M=10**9+7
while i*i<=N:
    cnt=1
    while N%i==0:
        cnt+=1
        N//=i
    ans*=cnt
    i+=1
if N!=1:ans*=2
print(int(ans%M))