N, M, X = map(int, input().split())
A = list(map(int, input().split()))
cnt = 0
min = 0
cnt_2 = 0
lists = list(range(N + 1))
for i in range(X, N + 1):
    for j in range(len(A)):
        if i == 0 or i == N or i == X:
            continue
        elif i == A[j]:
            cnt += 1
for m in range(X, -1, -1):
    for n in range(len(A)):
        if m == 0 or m == N or m == X:
            continue
        elif m == A[n]:
            cnt_2 += 1
if cnt > cnt_2:
    min = cnt_2
elif cnt_2 > cnt:
    min = cnt
print(min)