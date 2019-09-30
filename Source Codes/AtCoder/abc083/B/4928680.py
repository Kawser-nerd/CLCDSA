#083 B
N,A,B =map(int,input().split())
ans = 0
for i in range(N+1):
    tmp=0

    for j in range(len(str(i))):
        tmp+=int(str(i)[j])
    if A<=tmp<=B:
        ans +=i
print(ans)