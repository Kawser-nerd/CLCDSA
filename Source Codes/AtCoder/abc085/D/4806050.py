n,h = map(int,input().split())
a,b = [],[]
for i in range(n):
    c,d = map(int,input().split())
    a.append(c)
    b.append(d)
a_max = max(a)
b = sorted(b, reverse = True)

piv = 0
res = 0
while h > 0 and piv < n and b[piv] > a_max:
    res += 1
    h -= b[piv]
    piv += 1
if h > 0:
    res += (h + a_max - 1) // a_max
print(res)