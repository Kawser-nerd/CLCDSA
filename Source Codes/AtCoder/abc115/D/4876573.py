N, X = map(int, input().split())
a = [2**(i+2) - 3 for i in range(N+1)]  # ???
p = [2**(i+1) - 1 for i in range(N+1)]  # ?????
def f(N, X):
    if N == 0:
        return 1 if X > 0 else 0
    elif X <= 1 + a[N-1]:
        return f(N-1, X-1)
    else:
        return p[N-1] + 1 + f(N-1, X-2-a[N-1])
print(f(N, X))