a,b,c=map(int,input().split())
A=sorted([a,b,c])
ans=0
if max(A)%2==1:
    ans=A[0]*A[1]
print(ans)