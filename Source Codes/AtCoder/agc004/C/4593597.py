H, W = map(int, input().split())
A = []
for _ in range(H):
    A.append(input())

x, y = [], []
for i, a in enumerate(A):
    if i % 2:
        y.append('#' + a[1:])
        x.append('.' + '#' * (W-1))
    else:
        x.append(a[:-1] + '#')
        y.append('#' * (W-1) + '.')

print(*x, sep='\n')
print('')
print(*y, sep='\n')