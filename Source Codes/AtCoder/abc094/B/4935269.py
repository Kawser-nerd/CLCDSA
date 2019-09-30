N, M, X = map(int, input().split())
array = [0 for i in range(N+1)]
A = list(map(int, input().split()))
for i in range(M):
    array[A[i]] = 1
print(min(sum(array[:X]), sum(array[X+1:])))