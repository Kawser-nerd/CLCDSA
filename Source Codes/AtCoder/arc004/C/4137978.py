import math

if __name__ == '__main__':
    x, y = map(int, input().split('/'))
    mi = int(max(1., (x + math.sqrt(x*x + 2*y*y)) / y - 100))
    ma = int(2*x / y + 100)
    p = []
    for n in range(mi, ma):
        if (n*(n + 1)*y - 2*n*x) > 0 and (n*(n+1)*y - 2*n*x) % (2*y) == 0:
            m = (n*(n+1)*y - 2*n*x) // (2*y)
            if 1 <= m <= n:
                p.append([n, m])
    if len(p) == 0:
        print("Impossible")
    else:
        for nm in p:
            print(nm[0], nm[1])