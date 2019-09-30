from bisect import bisect_right

S = []
MX = 10**14

def palind(x):
    x = str(x)
    return x == ''.join(reversed(x))

def check(x):
    x = int(x)
    if (not palind(x)): return False
    if (not palind(x**2)): return False
    S.append(x**2)
    return True

def preprocess():
    for i in xrange(1,10**9):
        A = str(i)
        B = ''.join(reversed(A))
        X = A+B
        Y = A+B[1:]
        check(X)
        check(Y)
        if(int(Y)**2 > MX): break
    S.sort()

preprocess()
t = input()

def count(x):
    return bisect_right(S,x)

def solve(A,B):
    return count(B) - count(A-1)

for testc in range(1,t+1):
    print 'Case #%d:' % testc,
    A,B = map(int,raw_input().split())
    print solve(A,B)
