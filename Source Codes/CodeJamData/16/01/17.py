import sys

with open(sys.argv[1]) as f:
    lines = f.readlines()

T = int(lines[0],10)
for i, l in enumerate(lines[1:]):
    N = int(l,10)
    s = set()
    curr = 0
    times = 0
    if N == 0:
        print ("Case #%d:" % (i+1)), "INSOMNIA"
        continue
    while 1:
        curr += N
        times += 1
        #print curr
        for c in str(curr):
            s.add(c)
        if len(s) == 10:
            #print s
            break
    print ("Case #%d:" % (i+1)), curr

        

