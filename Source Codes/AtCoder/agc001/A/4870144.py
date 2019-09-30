N = int(input())
Ls = [int(x) for x in input().split()]

Ls.sort()
ans = 0
for i in range(0, len(Ls), 2):
    ans += min(Ls[i], Ls[i + 1])

print(ans)