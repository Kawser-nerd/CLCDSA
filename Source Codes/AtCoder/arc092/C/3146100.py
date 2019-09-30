n = int(input())
a = list(map(int, input().split()))
mx = max(a)
a[a.index(mx)] = abs(mx)
evn = sum(max(0, i) for i in a[::2])
odd = sum(max(0, i) for i in a[1::2])
if mx < 0:
    print(mx)
else:
    print(max(evn, odd))
oe = int(evn < odd)
res = []
beg = 0
while beg%2!=oe or a[beg]<0:
    res.append(1)
    beg += 1
end = n-1
while end%2!=oe or a[end]<0:
    res.append(end-beg+1)
    end -= 1
while beg < end:
    if a[end-2] < 0:
        res.append(end-beg-1)
    else:
        res.append(end-beg)
    end -= 2
print(len(res))
for i in res:
    print(i)