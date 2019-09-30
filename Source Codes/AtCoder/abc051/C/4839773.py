sx, sy, tx, ty = list(map(int, input().split()))

ans = 'R'
x = tx - sx
y = ty - sy
for _ in range(x-1):
    ans += 'R'
for _ in range(y):
    ans += 'U'
for _ in range(x):
    ans += 'L'
for _ in range(y):
    ans += 'D'
ans += 'LU'
for _ in range(y):
    ans += 'U'
for _ in range(x):
    ans += 'R'
ans += 'RD'
ans += 'RD'
for _ in range(y):
    ans += 'D'
for _ in range(x):
    ans += 'L'
ans += 'LU'

print(ans)