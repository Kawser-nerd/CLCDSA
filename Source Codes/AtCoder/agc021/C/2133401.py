R,C,A,B = map(int,input().split())
if (A+B)*2 > R*C:
    print('NO')
    exit()

ans = [['.' for j in range(C)] for i in range(R)]

if R%2:
    for i in range(C//2):
        if A == 0: break
        ans[-1][i*2] = '<'
        ans[-1][i*2+1] = '>'
        A -= 1
if C%2:
    for i in range(R//2):
        if B == 0: break
        ans[i*2][-1] = '^'
        ans[i*2+1][-1] = 'v'
        B -= 1

for i in range(R//2):
    for j in range(C//2):
        if A > 1:
            for k in range(2):
                ans[i*2+k][j*2] = '<'
                ans[i*2+k][j*2+1] = '>'
                A -= 1
        elif B > 1:
            for k in range(2):
                ans[i*2][j*2+k] = '^'
                ans[i*2+1][j*2+k] = 'v'
                B -= 1
        elif A == 1:
            ans[i*2][j*2] = '<'
            ans[i*2][j*2+1] = '>'
            A -= 1
        elif B == 1:
            ans[i*2][j*2] = '^'
            ans[i*2+1][j*2] = 'v'
            B -= 1

if R%2 and C%2 and B and ans[-2][-3] == '.':
    if ans[-1][-3] == '<':
        ans[-1][-2] = '<'
        ans[-1][-1] = '>'
    ans[-2][-3] = '^'
    ans[-1][-3] = 'v'
    B -= 1

if A > 0 or B > 0:
    print('NO')
else:
    print('YES')
    print(*[''.join(row) for row in ans], sep='\n')