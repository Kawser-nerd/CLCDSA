for ii in range(1,int(raw_input())+1):
    N = int(raw_input())
    f = [[int(a) for a in raw_input().split()] for j in range(N)]
    g = [sum([z[i] for z in f]) for i in range(6)]
    x = g[:3]
    d = g[3:]
    t = 0
    if (d != [0,0,0] and sum([x[i]*d[i] for i in range(3)]) < 0):
        t = -(0.0+sum([x[i] * d[i] for i in range(3)]))/sum([d[i] * d[i] for i in range(3)])
    x = [float(x[i] + t*d[i]) / N for i in range(3)]
    x = (x[0] * x[0] + x[1] * x[1] + x[2] * x[2]) ** 0.5
    print "Case #%d: %.8f %.8f" % (ii, x, t)
