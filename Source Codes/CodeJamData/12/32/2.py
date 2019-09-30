import sys

def best_time(D, positions):
    def f(a):
        start_t = 0
        tD = 0
        for i, (t, x) in enumerate(positions):
            if t > start_t and x < D and 0.5*a*(t-start_t)**2 > x:
                start_t = t - (2.*x/a)**0.5
            elif x >= D:
                (t1, x1) = positions[i-1]
                if x1 < D:
                    tD = t1 + (D-x1)*(t-t1)/(x-x1)
        return max(tD, start_t + (2.*D/a)**0.5)
    return f

fi = open("B.in", "r")
fo = open("B.out", "w")

T = int(fi.readline())
for case in range(T):
    D, N, A = fi.readline().split()
    D = float(D)
    N = int(N)
    A = int(A)
    positions = []
    for i in range(N):
        (t, x) = map(float, fi.readline().split())
        positions.append((t, x))
    a = map(float, fi.readline().split())
    result = map(best_time(D, positions), a)
    fo.write('Case #{0}:\n'.format(case+1))
    for i in range(A):
        fo.write('{0}\n'.format(result[i]))

print "Done"
fi.close()
fo.close()
