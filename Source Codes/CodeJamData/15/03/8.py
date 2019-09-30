tnum = int(raw_input())
def mult(a, b):
    s1, t1 = a
    s2, t2 = b
    s = s1*s2
    if t1=='1':
        return (s, t2)
    if t2=='1':
        return (s, t1)
    if t1==t2:
        return (-s, '1')
    if t2==chr((ord(t1)-ord('i')+1)%3+ord('i')):
        return (s, chr((ord(t2)-ord('i')+1)%3+ord('i')))
    else:
        return (-s, chr((ord(t1)-ord('i')+1)%3+ord('i')))

def powr(x, n):
    res = (1, '1')
    while n>0:
        if n%2==1:
            res = mult(res, x)
        x = mult(x, x)
        n /= 2
    return res

for test in range(tnum):
    _, n = [int(x) for x in raw_input().split()]
    s = raw_input().strip()
    try:
        p = powr(reduce(mult, [(1, x) for x in s]), n)
        if p!=(-1, '1'):
            raise Exception()
        S = [(1, x) for x in s*4]
        res = (1, '1')
        L1 = -1
        for i, x in enumerate(S):
            if res == (1, 'i'):
                L1 = i
                break
            res = mult(res, x)
        if L1==-1:
            raise Exception()
        res = (1, '1')
        L2 = -1
        for i, x in enumerate(reversed(S)):
            if res == (1, 'k'):
                L2 = i
                break
            res = mult(x, res)
        if L2==-1:
            raise Exception()
        if L1+L2>len(s)*n:
            raise Exception()
        print 'Case #{}: YES'.format(test+1)
    except Exception, e:
        print 'Case #{}: NO'.format(test+1)
