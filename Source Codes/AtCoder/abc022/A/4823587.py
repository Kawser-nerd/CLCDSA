import sys

n, s, t = [int(i) for i in sys.stdin.readline().rstrip().split()]

w = 0
ans = 0
for _ in range(n):
    a = int(sys.stdin.readline().rstrip())
    w += a
    if s <= w <= t:
        ans += 1

print(ans)