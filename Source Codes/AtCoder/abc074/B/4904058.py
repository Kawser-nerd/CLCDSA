N = int(input())
K = int(input())
x = list(map(int, input().split()))

ans = 0
for xi in x:
    ans += 2 * min(xi, K - xi)
print(ans)