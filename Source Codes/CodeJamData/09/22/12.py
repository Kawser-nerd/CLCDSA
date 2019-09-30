from codejam import *
import math

def pr(s, di):
    #print s, di
    s1 = s.lstrip(' (')
    if s1.find('(') == -1:
        return float(s1.lstrip(' ').rstrip(' )'))
    
    sp = s1.split()
    w = float(sp[0])
    rpr = sp[1]
    if rpr.find('(') != -1:
        rpr = rpr[:rpr.find('(')]
        
    
    i = j = s1.find('(') + 1
    d = 1
    while d > 0:
        j += 1
        if s1[j] == '(': d += 1
        if s1[j] == ')': d -= 1
    
    if rpr in di:
        return w * pr(s1[i-1:j+1], di)
    
    s1 = s1[j+1:]
    
    i = j = s1.find('(') + 1
    d = 1
    while d > 0:
        j += 1
        if s1[j] == '(': d += 1
        if s1[j] == ')': d -= 1
    
    return w * pr(s1[i-1:j+1], di) 
    
@codejam
def problem1(f):
    L = read_int(f)
    s = ''
    for n in xrange(L):
        s += read_str(f)
    A = read_int(f)
    r = ''
    for n in xrange(A):
        an = f.readline().rstrip('\r\n').split(' ')
        an.pop(0)
        an.pop(0)
        r += '\n'
        r += "%.7f" % pr(s, an)
    return r

@codejam
def problem2(f):
    s = read_str(f)
    n = len(s)
    p = [0] * n
    mp = [0] * n
    c = 0
    for i in range(10):
        for j in reversed(range(n)):
            if int(s[j]) == i:
                p[j] = c
                mp[c] = i
                c += 1
                
    #print p
    
    i = n - 2
    while i >= 0 and p[i] > p[i+1]:
        i -= 1
    if i < 0:
        p.reverse()
        for i in range(n):
            p[i] = mp[p[i]]
        p.insert(0, 0)
        i = 0
        while p[i] == 0: i += 1
        x = p.pop(i)
        p.insert(0, x)
        r = ''
        for x in p:
            r += str(x)
        
        return r
    
    j = n - 1
    while p[j] < p[i]:
        j -= 1
    t = p[i]
    p[i] = p[j]
    p[j] = t

    j = i + 1
    while j < n-1:
        m = j
        while m >= i+1 and p[m] > p[m+1]:
            t = p[m]
            p[m] = p[m+1]
            p[m+1] = t
            m -= 1
        j += 1

    #print p
    r = ''
    for i in range(n):
        r += str(mp[p[i]])
    return r

@codejam
def problem3(f):
    pass

problem2()