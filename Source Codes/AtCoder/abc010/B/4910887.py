n = int(input())
flowers = [int(i) for i in input().split()]

ans = 0
for i in flowers:
    while i % 2 == 0 or i % 3 == 2:
        ans += 1
        i -= 1

print(ans)