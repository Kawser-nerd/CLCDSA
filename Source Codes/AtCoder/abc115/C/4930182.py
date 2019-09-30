n, k = map(int, input().split())
heights = []
for _ in range(n):
    heights.append(int(input()))

heights.sort()

ans = float('inf')
for i in range(len(heights)):
    if i + k - 1 >= len(heights):
        break
    ans = min(ans, heights[i + k - 1] -  heights[i])

print(ans)