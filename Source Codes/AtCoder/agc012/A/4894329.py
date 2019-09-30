n=int(input())
a=sorted([int(i) for i in input().split()])[::-1]
ans=0
for i in range(1,2*n,2):
    ans+=a[i]
print(ans)