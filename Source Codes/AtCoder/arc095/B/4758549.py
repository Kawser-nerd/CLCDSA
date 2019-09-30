def upperbound(zs, left, right, ok):
    if left + 1 >= right:
        return left
    m = (left + right) // 2
    if ok(zs[m]):
        return upperbound(zs, m, right, ok)
    else:
        return upperbound(zs, left, m, ok)

n = int(input())
xs = list(map(int, input().split()))

ds = sorted(xs)

a = ds[-1]
c = a / 2
zs = [d - c for d in ds[:-1]]

i = upperbound(zs, 0, len(zs)-1, lambda z: z<=0)

j = i+1 if i < len(zs)-1 else i

b = ds[i] if abs(zs[i]) < abs(zs[j]) else ds[j]

print(a, b)