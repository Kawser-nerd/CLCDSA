import re

fin = open("smallB.in", "r")
fout = open("smallB.out", "w+")

for tc in xrange(int(fin.readline())):
    K,L,S = [int(x) for x in fin.readline().split()]
    KEYS = [x for x in fin.readline().strip()]
    TW = fin.readline().strip()

    pos = [""]
    for i in xrange(S):
        pos_next = []
        for p in pos:
            for key in KEYS:
                pos_next.append(p + key)
        pos = pos_next

    to_pay = [len(re.findall("(?=%s)" %TW, word)) for word in pos]

    to_bring = max(to_pay)
    med_pay = sum(to_pay)*1./len(to_pay)


    ans = to_bring - med_pay

    print "Case #%i: %f" %(tc+1, ans)
    fout.write("Case #%i: %f\n" %(tc+1, ans))