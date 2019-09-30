N=int(input())
ans=0
for i in range(N):
    a,b,c,d,e=map(int,input().split())
    if ans<a+b+c+d+(e*110/900):
        ans=a+b+c+d+(e*110/900)
print(ans)