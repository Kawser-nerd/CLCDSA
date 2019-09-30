N,M = map(int,input().split())
L= [int(input()) for i in range(M)]
used = set()
ans = []
for i in reversed(L):
    if i in used: continue
    ans.append(i)
    used.add(i)

for i in range(1,N+1):
    if i in used: continue
    ans.append(i)

print(*ans,sep="\n")