import itertools

n = int(input())

ans = 0
for r in range(1, 10):
    for s in itertools.product('357', repeat=r):
        d = int(''.join(s))
        if '3' in s and '5' in s and '7' in s and d <= n:
            ans += 1

print(ans)