N = int(input())
md = [[int(_) for _ in input().split("/")] for i in range(N)]

day_of_month = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

from itertools import accumulate

index_of_month = list(accumulate(day_of_month))

ds = [0] * 367

for i in range(1, len(ds), 7):
    ds[i] = 1

for i in range(7, len(ds), 7):
    ds[i] = 1

for m, d in md:
    i = index_of_month[m - 1] + d
    while ds[i] == 1 and i + 1 < len(ds):
        i += 1
    ds[i] = 1

result = max(len(r) for r in ("".join(chr(32 + c) for c in ds)).split())

print(result)