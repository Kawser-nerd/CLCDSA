N, M = map(int, input().split())

ans = [0]*N
for i in range(M):
    a, b = map(int, input().split())
    ans[a-1] += 1
    ans[b-1] += 1

for a in ans:
    print(a)