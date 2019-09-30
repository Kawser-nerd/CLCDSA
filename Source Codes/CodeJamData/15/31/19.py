fin = open("largeA.in", "r")
fout = open("largeA.out", "w+")

for tc in xrange(int(fin.readline())):
    R,C,W = [int(x) for x in fin.readline().split()]

    ans = (R-1)*(C/W)
    tmp = C
    while tmp >= W*2:
        ans += 1
        tmp -= W

    ans += min(tmp, W+1)


    print "Case #%i: %s" %(tc+1, ans)
    fout.write("Case #%i: %s\n" %(tc+1, ans))

