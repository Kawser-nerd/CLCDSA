N = int(input())

pairs = []
for i in range(N):
    a, b = map(int, input().split())
    pairs.append((a, b))
pairs = pairs[::-1]

total = 0
for a, b in pairs:
    a_dash = a + total
    mod = a_dash % b
    if mod > 0:
        total += b - mod
print(total)