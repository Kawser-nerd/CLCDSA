L, *B = map(int, open(0).read().split())
s = 0
for b in B:
    s ^= b
if s != 0:
    print(-1)
    exit(0)
e = 0
ans = [0]
for i in range(L-1):
    e ^= B[i]
    ans.append(e)
print(*ans, sep='\n')