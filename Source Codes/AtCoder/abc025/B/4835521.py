n, a, b = map(int, input().split())
# east: + west: - 
def f(x):
    if x < a:
        return a
    elif x > b:
        return b
    else:
        return x
ans = 0
for _ in range(n):
    s, d = input().split()
    d = int(d)
    ans += (1 if s == 'East' else -1) * f(d)
if ans == 0:
    print(0)
else:
    print('East {}'.format(ans) if ans >= 0 else 'West {}'.format(-(ans)))