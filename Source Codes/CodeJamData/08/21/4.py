case = "large"
input_file = "A-%s.in" % case
output_file = "A-%s.out" % case

fin = open(input_file)
fout = open(output_file, "w")

ncase = int(fin.readline().strip())

for z in xrange(1, ncase+1):
    n, A, B, C, D, x0, y0, M = [int(x) for x in fin.readline().strip().split()]
    X, Y = x0, y0
    rem = [[0]*3 for i in range(3)]
    rem[X%3][Y%3] += 1
    for i in xrange(1, n):
        X = (A * X + B) % M
        Y = (C * Y + D) % M
        rem[X%3][Y%3] += 1
    rems = [(a, b) for a in range(3) for b in range(3)]
    res = 0
    for x1, y1 in rems:
        q = rem[x1][y1]
        res += q * (q-1) * (q-2) / 6
    for x1, y1 in rems:
        for x2, y2 in [x for x in rems if x > (x1, y1)]:
            for x3, y3 in [x for x in rems if x > (x2, y2)]:
                if (x1 + x2 + x3) % 3 == 0 and (y1 + y2 + y3) % 3 == 0:
                    res += rem[x1][y1] * rem[x2][y2] * rem[x3][y3]
    print >> fout, "Case #%d:" % z, res

fin.close()
fout.close()
