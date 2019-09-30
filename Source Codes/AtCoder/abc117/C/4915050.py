N, M = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
if N >= M:
    print(0)
else:
    tmp = []
    for i in range(M - 1):
        tmp.append(A[i+1] - A[i])
    tmp.sort(reverse=True)
    interval = 0
    for i in range(N - 1):
        if i + 1 == M - 1:
            break
        interval += tmp[i]
    print(sum(tmp) - interval)