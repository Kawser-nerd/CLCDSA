# -*- coding: utf-8 -*-

fin = open("a.in","r")
T = int(fin.readline())

for i in range(T):
    line = fin.readline().strip()
    
    present = {}
    for c in line:
        present[c] = True
    
    base = len(present)
    if base < 2:
        base = 2
        
    digit = {}
    cn = 1
    for c in line:
        if c not in digit:
            digit[c] = cn
            if cn == 1:
                cn = 0
            elif cn == 0:
                cn = 2
            else:
                cn += 1
    
    rev = line[::-1]
    f = 1
    total = 0
    for c in rev:
        total += f * digit[c]
        f *= base
    print "Case #%d: %d" % (i+1, total)