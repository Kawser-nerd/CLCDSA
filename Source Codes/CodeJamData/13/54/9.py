import sys
sys.path.insert(0, '/home/rishig/codejam/')
from library import *

d = {}

# for i in range(21):
#     d[(tuple(range(i)), i)] = 0
# def first(lst,n):
#     assert len(lst) < n
#     for i in range(len(lst)):
#         if lst[i] != i:
#             return i
#     return len(lst)

def ecase(st,n):
    if st[-1] == '.':
        s = st
    else:
        f = st.find('.')
        if f == -1: return 0
        s = st[f+1:] + st[:f+1] # so l ends with a '.'
    if s in d:
        return d[s]
    assert s[-1] == '.'
    arr = []
    count = 0
    for i in range(n):
        if s[i] == '.':
            arr.append((count+1, s[:i] + 'X' + s[i+1:]))
            count = 0
        else:
            count += 1
    total = n-1.*sum(c*(c-1)/2 for c,s in arr)/n
    newtot = total + 1./n * sum(c*ecase(s,n) for c,s in arr)
    d[s] = newtot
    return newtot

def solvecase(case):
    S = f.readline().strip()
    n = len(S)
    return ecase(S, n)

if __name__ == '__main__':
    f = file(sys.argv[1])
    T = readint(f)
    sys.stderr.write(strftime("%H:%M:%S\n"))
    for case in range(1,T+1):
        ans = solvecase(case)
        print 'Case #%d: %s' % (case, ans)
        if T <= 15 or case == 1 or case % max((T//10),5) == 0:
            sys.stderr.write('completed case %d, ' % case)
            sys.stderr.write(strftime("%H:%M:%S\n"))
