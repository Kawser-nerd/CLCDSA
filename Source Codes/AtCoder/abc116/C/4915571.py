N = int(input())
heights = list(map(int, input().split()))

ans = heights[0]
sa =[0 for _ in range(N-1)]

for i in range(N-1):
    sa[i] += heights[i+1] - heights[i]

for i in range(N-1):
    if sa[i] > 0:
        ans += sa[i]

print(ans)