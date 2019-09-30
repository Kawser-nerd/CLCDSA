n=int(input())
ans=0
for i in range(n):
    a,b,c,d,e=[int(i) for i in input().split()]
    ans=max(ans,sum([a,b,c,d])+e*110/900)
print(ans)