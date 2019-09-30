n, k, q = map(int, input().split())
a = list(map(int, input().split()))
 
d = [a]
a = sorted(a)
ans = a[q - 1] - a[0]
 
while True:
    newd = list()
    li = list()
    for sub in d:
        for c in sub:
            if c != a[0]:
                li.append(c)
            else:
                newd.append(li)
                li = list()
        newd.append(li)
        li = list()
 
    d = list()
    a = list()
    for li in newd:
        if len(li) < k:
            continue
        else:
            d.append(li)
            li = sorted(li)
            a.extend(li[0:len(li) - k + 1])
 
    a.sort()
 
    if len(a) >= q:
        ans = min(a[q - 1] - a[0], ans)
    else:
        break
print(ans)