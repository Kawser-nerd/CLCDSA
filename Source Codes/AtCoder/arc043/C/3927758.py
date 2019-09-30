N = int(input())
*A, = map(int, input().split())
*B, = map(int, input().split())

C = [0]*(N+1)
D = [0]*(N+1)
for i in range(N):
    C[A[i]] = i
    D[B[i]] = i

data = [0]*(N+1)
def get(k):
    s = 0
    while k > 0:
        s += data[k]
        k -= k & -k
    return s
def add(k, x):
    while k <= N:
        data[k] += x
        k += k & -k

s = 0
R = []
for i, b in enumerate(B):
    c = C[b] - get(C[b]+1)
    s += c
    R.append(c)
    add(C[b]+1, 1)

if s % 2 == 1:
    print(-1)
    exit(0)

r = s // 2
j = 0
for i in range(N):
    if r < R[i]:
        j = i
        break
    r -= R[i]
V = []
for i in range(j):
    V.append(B[i])
for a in A:
    if D[a] < j:
        continue
    V.append(a)
a = B[j]
j = 0
while V[j] != a:
    j += 1
while r:
    V[j-1], V[j] = V[j], V[j-1]
    r -= 1; j -= 1
print(*V)