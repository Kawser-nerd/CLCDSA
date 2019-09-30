from itertools import accumulate
n=int(input())
A=list(map(int,input().split()))
A.sort()
S=list(accumulate(A))
cnt=1
for i in range(n-1):
    if 3*S[i]>=S[i+1]:
        cnt+=1
    else:
        cnt=1
print(cnt)