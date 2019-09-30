N, M, X = map(int, input().split())
A = [int(i) for i in input().split()]
n_1 = sum(X > x for x in A)
n_2 = sum((N - x) * (X - x) < 0 for x in A)
ans = min(n_1, n_2)
print(ans)