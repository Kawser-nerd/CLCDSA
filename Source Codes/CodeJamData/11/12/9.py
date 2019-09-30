import re

def sim(word, d, ls):
    #print word
    d = [w for w in d if len(w) == len(word)]
    seen = ""
    score = 0
    for l in ls:
        if seen == "":
            rep = re.compile(".")
        else:
            rep = re.compile("[^%s]" % (seen))
        wc = re.sub(rep, " ", word)
        #print wc
        #print l, seen
        for w in d:
            #print "test", w
            if l in w and re.sub(rep, " ", w) == wc:
                #print "found", w
                break
        else:
            #print "none found"
            continue
        seen += l
        if l not in word:
            #print "score lose", l
            score += 1
    return score

#d = """    potato
#    tomato
#    garlic
#    pepper""".split()
#print sim("potato", d, "zyxwvutsrqponmlkjihgfedcba")

for c in xrange(input()):
    #break
    #print 
    #print c
    dn, ln = map(int, raw_input().split())
    d = []
    for i in xrange(dn):
        d.append(raw_input())
    print "Case #%d:" % (c+1),
    for i in xrange(ln):
        ls = raw_input()
        #print ls
        w = max(d, key=lambda w: sim(w, d, ls))
        print w,
        #break
    print
    #break