def makeSeg(array):
    fin = 0
    n = len(array)
    seg = []
    seg.append([0, n, array[0][0], array[n-1][0], 1.0, 0.0])
    parent = 0
    while True:
        if fin >= n:
            break
        l = seg[parent][0]
        r = seg[parent][1]
        if r-l <= 1:
            seg.append([0, 0, 0, 0, 1.0, 0.0])
            seg.append([0, 0, 0, 0, 1.0, 0.0])
            fin += 1
            parent += 1
            continue
        m = (l+r+1)//2
        seg.append([l, m, array[l][0], array[m-1][0], 1.0, 0.0])
        seg.append([m, r, array[m][0], array[r-1][0], 1.0, 0.0])
        parent += 1
    return seg

def left(i):
    return 2*i+1

def right(i):
    return 2*i+2

def mother(i):
    return (i+1)//2 - 1

def search(seg, key):
    now = 0
    while True:
        if seg[now][1] - seg[now][0] <= 1:
            return now
        if key <= seg[left(now)][3]:
            now = left(now)
        else:
            now = right(now)

def update(seg, exe):
    now = search(seg, exe[0])
    seg[now][4] = exe[1]
    seg[now][5] = exe[2]
    while now > 0:
        now = mother(now)
        l = left(now)
        r = right(now)
        seg[now][4] = seg[l][4]*seg[r][4]
        seg[now][5] = seg[l][5]*seg[r][4] + seg[r][5]
        
    return seg



n, m = map(int, input().split())

if m==0:
    print(1)
    print(1)
else:
    a = []

    for i in range(m):
        x = list(input().split())
        x[0] = int(x[0])
        x[1] = float(x[1])
        x[2] = float(x[2])
        a.append(x)

    b = sorted(a, key=lambda x:x[0])

    c = []
    pre = 0
    for i, bs in enumerate(b):
        if i==0 or pre!=bs[0]:
            pre = bs[0]
            c.append(bs)

    seg = makeSeg(c)
    mini = 1
    maxi = 1
    for i in range(m):
        seg = update(seg, a[i])
        rec = seg[0][4]+seg[0][5]
        if rec < mini:
            mini = rec
        elif rec > maxi:
            maxi = rec

    print(mini)
    print(maxi)