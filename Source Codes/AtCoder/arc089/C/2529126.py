# seishin.py
A, B = map(int, input().split())
D = [list(map(int, input().split())) for i in range(A)]

N = 101
F = [[0]*N for i in range(N)]
for a in range(N):
    for b in range(N):
        res = 0
        for x in range(A):
            for y in range(B):
                res = max(res, D[x][y] - (x+1)*a - (y+1)*b)
        F[a][b] = res

for x in range(A):
    for y in range(B):
        v = 101
        for a in range(N):
            for b in range(N):
                v = min(v, (x+1)*a + (y+1)*b + F[a][b])
        if v != D[x][y]:
            print("Impossible")
            exit(0)
print("Possible")
print(2*N, N**2 + 2*(N-1))
ans = 0
for i in range(N-1):
    print(i+1, i+2, "X")
    print(103+i, 102+i, "Y")
    ans += 2
for a in range(N):
    for b in range(N):
        ans += 1
        print(a+1, 102+b, F[a][b])
print(1, 102)