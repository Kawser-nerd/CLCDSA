a = list(input())
b = list(input())

c = []

aa = len(a)
bb = len(b)

if aa == bb:
    for i in range(aa):
        x = a[i] 
        y = b[i]
        c.append(x)
        c.append(y)
else:
    m = a.pop(-1)
    for i in range(aa -1):
        x = a[i] 
        y = b[i]
        c.append(x)
        c.append(y)
    c.append(m)
        
print(''.join(c))