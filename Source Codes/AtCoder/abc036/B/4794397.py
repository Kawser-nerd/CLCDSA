n = int(input())
s = []
for i in range(n):
    s.append(list(map(str, input())))
t = [['-' for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        t[i][j] = s[n - j - 1][i]
for i in range(n):
    print(''.join(t[i]))