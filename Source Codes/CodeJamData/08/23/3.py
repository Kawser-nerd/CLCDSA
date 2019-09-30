case = "small-attempt0"
input_file = "C-%s.in" % case
output_file = "C-%s.out" % case

fin = open(input_file)
fout = open(output_file, "w")

ncase = int(fin.readline().strip())

for z in xrange(1, ncase+1):
    print >> fout, "Case #%d:" % z,
    k = int(fin.readline().strip())
    d = [int(x) - 1 for x in fin.readline().strip().split()[1:]]
    for dd in d:
        n, p, r, i = k, dd, 0, 1
        #print n, p, r, i
        while p != r:
            n -= 1
            if p > r:
                p -= 1
            r = (r + i) % n
            i += 1
            #print n, p, r, i
        print >> fout, i,
    print >> fout

fin.close()
fout.close()
