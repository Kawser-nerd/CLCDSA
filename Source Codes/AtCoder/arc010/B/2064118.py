N = int(input())
D = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
A = 366
E = [0]*13
for i in range(12):
    E[i+1] = E[i] + D[i]
yasumi = [0]*A
youbi = 6
for i in range(A):
    yasumi[i] = (youbi >= 5)
    youbi = (youbi + 1) % 7
for i in range(N):
    m, d = map(int, input().split('/'))
    d += E[m-1] - 1
    while d < A-1 and yasumi[d]:
        d += 1
    yasumi[d] = 1
cnt = ans = 0
for i in range(A):
    if yasumi[i]:
        cnt += 1
        ans = max(cnt, ans)
    else:
        cnt = 0
print(ans)