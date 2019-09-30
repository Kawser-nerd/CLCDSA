n = int(input())
yayo = [0] * (1000010)
for i in range(n):
    a, b = map(int, input().split())
    yayo[a] += 1
    yayo[b + 1] -= 1
for i in range(1000000):
    yayo[i + 1] += yayo[i]
print(max(yayo))