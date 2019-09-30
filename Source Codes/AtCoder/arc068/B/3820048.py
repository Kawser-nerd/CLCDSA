from collections import Counter
N=int(input())
A=list(map(int,input().split()))
Ac=dict(Counter(A))
a=0
b=0
for i in Ac.keys():
    if Ac[i]>1:
        a+=Ac[i]-1
if a%2==0:
    print(N-a)
else:
    print(N-a-1)