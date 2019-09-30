N=list(input())
ans=int(N[0])-1
ans+=9*(len(N)-1)
ans2=0
for n in N:ans2+=int(n)
print(max(ans,ans2))