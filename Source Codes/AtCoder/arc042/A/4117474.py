N,M=map(int,input().split())
A=[int(input()) for i in range(M)][::-1]
ans=[]
s=set()
for a in A:
    if a not in s:ans.append(a)
    s.add(a)
for i in range(1,N+1):
    if i not in s:ans.append(i)
print(*ans,sep="\n")