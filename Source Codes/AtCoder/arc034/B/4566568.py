n = int(input())
f = []

for  i in range(30):
    if n < 10 ** i:
        a = i
        break

for j in range(1, a * 9):
    b = n - j
    s = b
    c = []
    while s > 0:
            c.append(s%10)
            s //= 10
    e = sum(c)
    if e == j:
            f.append(b)



if len(f) == 0:
        print(0)

else:
        f.sort()
        print(len(f))
        for t in range(len(f)):
                print(f[t])