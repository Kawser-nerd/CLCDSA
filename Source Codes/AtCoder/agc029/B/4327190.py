from collections import Counter
input()
A=list(map(int,input().split()))
A.sort(reverse=True)
C=Counter(A)
ans=0
for a in A:
    if not C[a]:
        continue
    C[a]-=1
    t=2**a.bit_length()-a
    if C[t]:
        C[t]-=1
        ans+=1
print(ans)