n, a, b = map(int, input().split())

ans = 0
for _ in range(n):
    s, d = input().split()
    x = int(d)
    if x < a:
        x = a
    elif x > b:
        x = b
    if s == 'West':
        x *= -1
    ans += x

if ans == 0:
    print(0)
elif ans > 0:
    print('East', ans)
else:
    print('West', -ans)