import sys

import psyco; psyco.full()

def main():
    cipher = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
    plain  = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

    trans = {}
    trans["q"] = "z"
    trans["z"] = "q"
    for i in xrange(len(cipher)):
        if cipher[i] not in trans:
            trans[cipher[i]] = plain[i]
            
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for i in xrange(ncases):
        line = f.readline().strip()
        s = ""
        for c in line:
            s += trans[c]
            
        print "Case #%d: %s" % (i+1, s)
        
main()