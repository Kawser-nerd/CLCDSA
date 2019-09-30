N,A,B=[int(i) for i in input().split()]
ans=0
for i in range(1,N+1):
    L=len(str(i))
    count=0
    for j in range(L):
        count=count+int(str(i)[j])
    if A<=count<=B:
        ans+=i
    else:
        continue
print(ans)