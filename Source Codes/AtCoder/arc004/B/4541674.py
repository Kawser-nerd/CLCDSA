N = int(input())
ds = [int(input()) for _ in range(N)]

maxD = max(ds)
sumD = sum(ds)

print(sumD)
print(max(0, maxD - (sumD - maxD)))