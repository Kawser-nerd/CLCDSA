a = int(input())
ar = []
for i in range(a):
    l = input()
    ar.append(l)
br = set(list(ar[0]))
dr = []
for r in br:
    cr =[]
    count = 0
    for rr in ar:
        if rr.count(r) > 0:
            cr.append(rr.count(r))
            count += 1
        if count == a:
            for i in range(min(cr)):
                dr.append(r)
print("".join(sorted(dr)))