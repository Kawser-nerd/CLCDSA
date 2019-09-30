n=int(input())
t=[int(input()) for i in range(n)]
total=sum(t)
ans=[]
for i in range(2**n):
    ln=[0]*n
    for j in range(n):
        if ((i>>j)&1):
            ln[n-j-1]=1
    a=sum([t[k]*ln[k] for k in range(n)])
    ans.append(max(total-a,a))
print(min(ans))