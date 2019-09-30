N = int(input())
A = list(map(int, input().split()))

# ??????????????
M, M_index = 0, -1
for i, a in enumerate(A):
    if abs(M) <= abs(a):
        M = a
        M_index = i

# ??????M???
for i in range(N):
    A[i] += A[M_index]
ans = [(M_index, i) for i in range(N)]

# ??????????
if M >= 0:
    for i in range(N - 1):
        if A[i] > A[i + 1]:
            A[i + 1] += A[i]
            ans.append((i, i + 1))
else:
    for i in range(N - 1, 0, -1):
        if A[i - 1] > A[i]:
            A[i - 1] += A[i]
            ans.append((i, i - 1))

print(len(ans))
for x, y in ans:
    print(x + 1, y + 1)