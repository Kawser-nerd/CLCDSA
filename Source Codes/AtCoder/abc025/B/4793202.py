n, a, b = map(int, input().split())
pos = 0

for _ in range(n):
    s, d = input().split()
    d = min(b, max(a, int(d)))

    if s == 'East':
        pos += d
    else:
        pos -= d

if pos > 0:
    print('East', pos)
elif pos < 0:
    print('West', -pos)
else:
    print(0)