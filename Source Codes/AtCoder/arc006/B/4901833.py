n, l = map(int, input().split())
v = [[-1] * n for i in range(l)]
for i in range(l):
    s = input()
    for j in range(n-1):
        if s[j*2+1] == '-':
            v[i][j] = j+1
            v[i][j+1] = j
y = 0
s = input()
for i in range(n):
    if s[i*2] == 'o':
        y = i
        break
for i in range(l-1, -1, -1):
    if v[i][y] != -1:
        y = v[i][y]
print(y+1)