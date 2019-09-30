n = int(input())
xs = list(map(int, input().split()))
ds = sorted(xs)
m = n // 2 - 1

bs = [ds[m] if xs[i] > ds[m] else ds[m+1] for i in range(n)]

print("\n".join(map(str, bs)))