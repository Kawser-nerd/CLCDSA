import bisect
N = int(input())
W = [int(input()) for i in range(N)]

ds = [W[0]]
for w in W[1:]:
    i = bisect.bisect_left(ds,w)
    if i == len(ds):
        ds.append(w)
    else:
        ds[i] = w
print(len(ds))