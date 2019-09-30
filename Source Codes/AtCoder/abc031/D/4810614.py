k, n = map(int, input().split())

vw = []

for _ in range(n):
    a, b = input().split()
    vw.append([list(map(lambda x:int(x)-1, list(a))), list(b)])

d = [0] * k

#print(vw)

while 1:
    for i in range(k-1):
        if d[i] == 3:
            d[i] = 0
            d[i+1] += 1
    else:
        if d[k-1] >= 3:
            break
    #print(d)
    c = [[] for _ in range(k)]
    flag = 0
    for v, w in vw:
        p = 0
        for x in v:
            if p + d[x] >= len(w):
                #print(x, p+d[x], len(w), c, v, w)
                flag = 1
                break
            elif len(c[x]) > 0:
                if ''.join(c[x]) != ''.join(w[p:p+d[x]+1]):
                    #print(''.join(c[x]) , ''.join(w[p:p+d[x]+1]))
                    flag = 1
                    break
            else:
                c[x] = [] + w[p:p+d[x]+1]
            p += d[x] + 1
        if p != len(w):
            flag = 1
            break
        elif flag == 1:
            break
    if flag == 0:
        break
    #print(c)
    d[0] += 1

for x in c:
    print(''.join(x))