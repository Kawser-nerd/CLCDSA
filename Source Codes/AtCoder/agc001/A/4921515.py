N = int(input())

L = list(map(int, input().split()))

L.sort()

ans = 0
for i in range(0, len(L), 2):
    ans += L[i]

print(ans)