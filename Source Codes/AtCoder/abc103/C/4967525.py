N = int(input())
ai = list(map(int, input().split()))

ans = 0
for a in ai:
    ans += a - 1

print(ans)