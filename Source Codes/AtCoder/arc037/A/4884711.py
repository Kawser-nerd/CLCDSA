n=int(input())
ans=0
m=[int(i) for i in input().split()]
for i in m:
    if i<80:
        ans+=80-i
print(ans)