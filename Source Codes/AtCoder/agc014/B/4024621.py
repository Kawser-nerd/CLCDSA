N, M = map(int, input().split())
Path = [0 for i in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a, b = min(a, b), max(a, b)
    Path[b-1] += 1
    if a > 1:
        Path[a-1] += 1

for p in Path:
    if p % 2 != 0:
        print("NO")
        break
else: print("YES")