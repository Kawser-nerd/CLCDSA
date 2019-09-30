N,M = map(int,input().split())
src = [tuple(map(int,input().split())) for i in range(M)]
k = [0]*N
for a,b in src:
    a,b = a-1,b-1
    k[a] += 1
    k[b] += 1
print('NO' if any(a%2 for a in k) else 'YES')