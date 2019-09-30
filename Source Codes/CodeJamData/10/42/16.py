
def bs(l, r, m, p, price):
    if max(m) == 0:
        return 0
    if p == 1:
        return price[1][l / 2]
    ll = l
    lr = (l + r) / 2
    rl = lr + 1
    rr = r
    pr = price[p][l / 2**p]
    if max(m) < p:
        b = (bs(ll, lr, m[0:(rl - ll)], p - 1, price) +
             bs(rl, rr, m[(rl - ll):2**p], p - 1, price))
    else:
        b = -1
    for i in xrange(len(m)):
        if m[i] > 0:
            m[i] -= 1
    nb = pr + (bs(ll, lr, m[0:(lr - ll + 1)], p - 1, price) +
               bs(rl, rr, m[(lr - ll + 1):2**p], p - 1, price))
    if b >= 0 and nb > b:
        return b
    else:
        return nb

filename = 'B-large'

fin = open(filename + '.in')
fout = open(filename + '.out', 'w')
cases = int(fin.readline().strip())
for case in xrange(1, cases + 1):
    p = int(fin.readline().strip())
    m = [p - int(x) for x in fin.readline().strip().split()]
    price=[[]]
    for i in xrange(p):
        price.append([int(x) for x in fin.readline().strip().split()])
    ans = bs(0, 2**p - 1, m, p, price)
    print ans
    fout.write('Case #%d: %d\n' % (case, ans))
fin.close()
fout.close()
