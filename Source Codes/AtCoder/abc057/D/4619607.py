def conb(a,b):
    now=1
    for i in range(b):
        now=int(now*(a-i)/(i+1))
    return now
N,A,B=map(int,input().split())
V=list(map(int,input().split()))
V.sort(reverse=True)
line=V[A-1]
if V[0]==line:
    ans=0
    for i in range(A,min(V.count(V[0]),B)+1):
        ans+=conb(V.count(V[0]),i)
    print(V[0])
    print(ans)
elif line>V[A]:
    print(sum(V[:A])/A)
    print(1)
else:
    idx=V.index(line)
    cnt=V.count(line)
    print((sum(V[:idx])+line*(A-idx))/A)
    print(conb(cnt,A-idx))