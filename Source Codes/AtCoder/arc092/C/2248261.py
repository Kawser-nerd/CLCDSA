n = int(input())
a = list(map(int, input().split()))
use = [False]*n
mx = max(a)
if mx < 0:
    use[a.index(mx)] = True
else:
    evn = sum(max(i, 0) for i in a[::2])
    odd = sum(max(i, 0) for i in a[1::2])
    mx = max(evn, odd)
    for i in range(int(evn<odd), n, 2):
        if a[i] > 0:
            use[i] = True
print(mx)
beg = 0
while not use[beg]:
    beg += 1
res = [1]*beg
end = n-1
while beg < end:
    if use[end]:
        if use[end-2]:
            a[end-2] += a[end]
            res.append(end-beg)
            end -= 2
            use[end] = True
        else:
            res.append(end-beg-1)
            a[end-2] = a[end]
            end -= 2
            use[end] = True
    else:
        res.append(end-beg+1)
        end -= 1
print(len(res))
for i in res:
    print(i)