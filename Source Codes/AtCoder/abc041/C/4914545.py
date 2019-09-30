N, *a = map(int, open(0).read().split())
A = []
for i in range(N):
    A.append((a[i], i+1))
A.sort(key=lambda x: x[0], reverse=True)
for i in range(N):
    print(A[i][1])