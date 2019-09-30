N, M = map(int, input().split())
A = list(map(int, input().split()))
A.sort()

dif = []
for i in range(M-1):
    dif.append(A[i+1] - A[i])

dif.sort(reverse=True)
dif = dif[N-1:]

print(sum(dif))