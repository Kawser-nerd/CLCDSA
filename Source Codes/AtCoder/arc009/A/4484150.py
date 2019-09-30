N = int(input())
ab = [map(int,input().split()) for _ in range(N)]
ans = 0
for ai,bi in ab:
    ans += ai*bi
print(int(ans*1.05))