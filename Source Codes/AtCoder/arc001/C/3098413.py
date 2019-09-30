N = 8
row = [-1] * N
col = [-1] * N
dpos = [-1] * (2 * N - 1)
dneg = [-1] * (2 * N - 1)
 
def solve(i):
    if i == N:
        for i in range(N):
            print(''.join('.Q'[row[i]==j] for j in range(N)))
        exit()
    if row[i] != -1:
        solve(i + 1)
        return
    for j in range(N):
        if 1 in (col[j], dpos[i + j], dneg[i - j + N - 1]):
            continue
        row[i] = j; col[j] = dpos[i + j] = dneg[i - j + N - 1] = 1
        solve(i + 1)
        row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = -1
 
for i in range(N):
    r = input()
    if 'Q' in r:
        j = r.index('Q')
        if r.count('Q') > 1 or 1 in (col[j], dpos[i + j], dneg[i - j + N - 1]):
            print('No Answer')
            exit()
        row[i] = j; col[j] = dpos[i + j] = dneg[i - j + N - 1] = 1
solve(0)
print('No Answer')