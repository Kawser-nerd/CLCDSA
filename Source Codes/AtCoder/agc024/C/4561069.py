import sys

N = int(input())
a = list(map(int, sys.stdin))
current = a[-1]
ans = a[-1]

for n in a[-2::-1]:
    if current-1 > n:
        print(-1)
        exit()
    if current <= n:
        ans += n
    current = n

print(ans if current == 0 else -1)