i,o,t,j,l,s,z = map(int,input().split())
a = 0
b = 0
if i > 0 and j > 0 and l > 0:
    a += 3
    for k in [i-1,j-1,l-1]:
        if k % 2 == 1:
            a += k-1
        else:
            a += k

for k in [i,j,l]:
        if k % 2 == 1:
            b += k-1
        else:
            b += k
print(o + max(a,b))