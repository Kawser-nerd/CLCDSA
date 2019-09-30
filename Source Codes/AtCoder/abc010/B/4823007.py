n = int(input())
A = list(map(int, input().split()))

ans = 0
for a in A:
    if a%2 == 0:
        ans += 1
        a -= 1
    if a%3 == 2:
        ans += 2

print(ans)