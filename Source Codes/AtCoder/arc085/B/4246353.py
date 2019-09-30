N, Z, W = map(int, input().split())
a = list(map(int, input().split()))
print(max(abs(a[N - 1] - a[N - 2]), abs(a[N - 1] - W)))