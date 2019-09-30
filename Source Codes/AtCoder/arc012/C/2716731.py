L = 19
S = [input() for i in range(L)]

O = sum(s.count('o') for s in S)
X = sum(s.count('x') for s in S)

if not X <= O <= X+1:
    print("NO")
    exit(0)

M = 5
def line(c, r, h):
    for i in range(L-M+1):
        for j in range(L):
            cnt = 0
            for k in range(M):
                cnt += ((i+k != c or j != r) and S[i+k][j] == h)
            if cnt == M:
                return 1
    for i in range(L):
        for j in range(L-M+1):
            cnt = 0
            for k in range(M):
                cnt += ((i != c or j+k != r) and S[i][j+k] == h)
            if cnt == M:
                return 1
    for i in range(L-M+1):
        for j in range(L-M+1):
            cnt = 0
            for k in range(M):
                cnt += ((i+k != c or j+k != r) and S[i+k][j+k] == h)
            if cnt == M:
                return 1
            cnt = 0
            for k in range(M):
                cnt += ((i+M-1-k != c or j+k != r) and S[i+M-1-k][j+k] == h)
            if cnt == M:
                return 1
    return 0

def check(c, r):
    return line(c, r, 'o') or line(c, r, 'x')

if not check(-1, -1):
    print("YES")
    exit(0)

for i in range(L):
    for j in range(L):
        if O == X and S[i][j] == 'x':
            if not check(i, j):
                print("YES")
                exit(0)
        if O == X+1 and S[i][j] == 'o':
            if not check(i, j):
                print("YES")
                exit(0)
print("NO")