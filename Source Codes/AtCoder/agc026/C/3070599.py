from collections import defaultdict
N=int(input())
S=input()
A=S[:N]
B=S[N:]
B=B[::-1]
def f(A):
    dd=defaultdict(int)
    for i in range(1<<N):
        a=''
        b=''
        for j in range(N):
            if i&(1<<j):
                a+=A[j]
            else:
                b+=A[j]
        dd[(a,b)]+=1
    return dd
dd1=f(A)
dd2=f(B)
ans=0
for t,c in dd1.items():
    ans+=dd2[t]*c
print(ans)