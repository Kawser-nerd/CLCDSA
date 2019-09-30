n = int(input())
c = [0, 1, 0, 1, 2, 3, 0, 1, 0]
ans = 0
for b in map(int, input().split()):
    ans += c[b-1]
print(ans)