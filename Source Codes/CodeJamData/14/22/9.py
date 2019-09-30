

file_in = open('b.in', 'r')
file_out = open('b.out', 'w')

n_case = int(file_in.readline())

for i_case in range(n_case):
    print i_case

    A, B, K = (int(s) for s in file_in.readline().split())
    count = 0
    for a in xrange(A):
        for b in xrange(B):
            if a & b < K:
                count += 1

    file_out.write("Case #%d: %s\n" % (i_case + 1, str(count)))

file_in.close()
file_out.close()
