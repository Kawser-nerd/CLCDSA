n=int(input())
l=list(map(int,input().split()))
s=sum(l)/(n-l.count(0))
ans=int(s)+((s-int(s))>0)
print(ans)