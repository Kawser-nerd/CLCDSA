import sys

fp = open(sys.argv[1])
nks = int (fp.readline())

for ks in range(1,nks+1):
    org = fp.readline();
    if org [-1] == "\n":
        org = org[:-1]
    ccnt = {}
    for c in org:
        if c=='\n': continue
        try:
            ccnt[c] += 1
        except:
            ccnt[c] = 1
        
    #print ccnt
    lcnt = []
    for c in ccnt:
        lcnt.append(ccnt[c])
    lcnt = sorted(lcnt)
    
    
    #print lcnt
    
    idx = 0
    base_array = "1023456789abcdef"
    assert(len(lcnt) <= len(base_array)), "fuck!!"
    strmap =  {}
    new = ""
    for c in org:
        try :
            fucker = strmap[c]
        except:
            strmap[c] = base_array[idx]
            idx += 1
        new += strmap[c]
    
    print "Case #%d: %d" %(ks, int(new, max(len(lcnt),2)))
