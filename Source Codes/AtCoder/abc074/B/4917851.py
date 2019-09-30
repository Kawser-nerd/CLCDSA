n = int(input())
k = int(input())
x = [int(item) for item in input().split()]
ans = 0
for x_ in x:
    ans += min(abs(x_-0), abs(x_-k)) * 2
print(ans)