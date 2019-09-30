N, M = map(int, input().split())
L = [list(map(int, input().split())) for i in range(N)]
x = [0] * N
x1 = [0] * N
a1 = 0
for i in range(N):
    x[i] = sum(L[i])
x1 = sorted(x, reverse=True)
for i in range(M):
    a1 += x1[i]
#print(a1)

x2 = [0] * N
a2 = 0
for i in range(N):
    x[i] = L[i][0] + L[i][1] - L[i][2]
x2 = sorted(x, reverse=True)
for i in range(M):
    a2 += x2[i]
#print(a2)

x3 = [0] * N
a3 = 0
for i in range(N):
    x[i] = L[i][0] - L[i][1] + L[i][2]
x3 = sorted(x, reverse=True)
for i in range(M):
    a3 += x3[i]
#print(a3)

x4 = [0] * N
a4 = 0
for i in range(N):
    x[i] = L[i][0] - L[i][1] - L[i][2]
x4 = sorted(x, reverse=True)
for i in range(M):
    a4 += x4[i]
#print(a4)

x5 = [0] * N
a5 = 0
for i in range(N):
    x[i] = -L[i][0] + L[i][1] + L[i][2]
x5 = sorted(x, reverse=True)
for i in range(M):
    a5 += x5[i]
#print(a5)

x6 = [0] * N
a6 = 0
for i in range(N):
    x[i] = -L[i][0] + L[i][1] - L[i][2]
x6 = sorted(x, reverse=True)
for i in range(M):
    a6 += x6[i]
#print(a6)

x7 = [0] * N
a7 = 0
for i in range(N):
    x[i] = -L[i][0] - L[i][1] + L[i][2]
x7 = sorted(x, reverse=True)
for i in range(M):
    a7 += x7[i]
#print(a7)

x8 = [0] * N
a8 = 0
for i in range(N):
    x[i] = -L[i][0] - L[i][1] - L[i][2]
x8 = sorted(x, reverse=True)
for i in range(M):
    a8 += x8[i]
#print(a8)

print(max(a1, a2, a3, a4, a5, a6, a7, a8))
# 8?????????