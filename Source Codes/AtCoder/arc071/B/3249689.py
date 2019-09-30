from itertools import accumulate

n, m = map(lambda x: int(x)-1, input().split())
x_a = list(map(int, input().split()))
x_a = [c-p for p, c in zip(x_a, x_a[1:])]
y_a = list(map(int, input().split()))
y_a = [c-p for p, c in zip(y_a, y_a[1:])]
mod = 10**9+7
x = 0
for mul, x1, x2 in zip(accumulate(range(n, 0, -2)), x_a[:n//2]+[0], x_a[::-1]):
    x = (x+mul*(x1+x2))%mod
ans = 0
for mul, y1, y2 in zip(accumulate(range(m, 0, -2)), y_a[:m//2]+[0], y_a[::-1]):
    ans = (ans+mul*(y1+y2)*x)%mod
print(ans)