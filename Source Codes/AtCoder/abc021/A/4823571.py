import sys

n = int(sys.stdin.readline().rstrip())

div, mod = divmod(n, 2)

ans = 0
if mod:
    ans += 1
ans += div

print(ans)
if mod:
    print(1)
for _ in range(div):
    print(2)