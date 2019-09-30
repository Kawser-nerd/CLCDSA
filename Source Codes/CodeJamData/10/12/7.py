from sys import stdin

N = 256

def main():
    dd, ii, mm, n =map(int, stdin.readline().split())
    A = map(int, stdin.readline().split())
    x = [0]*N
    for a in A:
        y = []
        for v in x:
            y.append(v + dd)
        for i in xrange(N):
            y[i] = min(y[i], min(x[max(0,i-mm):min(i+mm+1, N)]) + abs(i-a))
        for i in xrange(N):
            for j in xrange(i+1, min(N, i+mm+1)):
                y[j] = min(y[j], y[i] + ii)
        for i in xrange(N):
            for j in xrange(i+1, min(N, i+mm+1)):
                y[N-1-j] = min(y[N-1-j], y[N-1-i] + ii)
        x = y

    return str(min(x))

tno = int(stdin.readline())
for i in xrange(0, tno):
    print "Case #%d: %s"%(i+1, main())
