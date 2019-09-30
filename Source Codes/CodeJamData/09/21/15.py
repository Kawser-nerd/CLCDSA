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
    pass

@codejam
def problem3(f):
    pass

problem1()