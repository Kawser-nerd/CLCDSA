tnum = input()
for tcou in range(tnum):
    n = input()
    if n==0:
        answer = "INSOMNIA"
    else:
        m = 0
        s = set()
        while True:
            m += n
            for x in str(m):
                s.add(x)
            if len(s)==10:
                answer = m
                break
    print "Case #{}: {}".format(tcou+1, answer)
