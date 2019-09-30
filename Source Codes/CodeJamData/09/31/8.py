n = int(raw_input())

for i in range(n):
    s = raw_input()
    symbols = {}
    if len(s) == 1:
        print "Case #%d: %d"%(i+1, 1)
        continue
    for j in s:
        symbols[j] = None
    base = len(symbols)
    if base == 1:
        print "Case #%d: %d"%(i+1, 2**len(s)-1)
        continue
#    print "base: ", base
    curnum = 1
    val = 0
    for j in s:
        if symbols[j] == None:
            symbols[j] = curnum
            if curnum == 1:
                curnum = 0
            elif curnum == 0:
                curnum = 2
            else:
                curnum = curnum + 1
        val = val * base + symbols[j]
    print "Case #%d: %d"%(i+1, val)
