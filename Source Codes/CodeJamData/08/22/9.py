from time import time
import psyco
import re
import math
psyco.full()

fin = open("2_input.txt","r")
fout = open("2_output.txt","w")
cases = int(fin.readline())
cached = {}
#
def isprime(n):
    global cached
    if n in cached:
        return cached[n]
    if n == 2: return True
    for x in range(2, int(n**0.5)+1):
        if n % x == 0:
            cached[n] = False
            return False
    cached[n] = True
    return True

def check_for_p(a,b,p):
    for num in range(p, b):
        if isprime(num) and (a % num == 0 and b % num == 0):
            return True
    return False

t0 = time()
for casenr in range(cases):
    (A,B,P) = map(int, [e for e in fin.readline().split()])
    n = B-A
    set_id = {}
    for i in range(A,B+1):
        set_id[i] = i-A
    
    #print set_id
    
    set_count = n+1
    for p0 in range(A,B+1):
        for p1 in range(p0+1, B+1):
            if (set_id[p0] == set_id[p1]):
                continue
            if check_for_p(p0,p1,P):
                set_count -= 1
                ex = set_id[p1]
                for k in set_id.keys():
                    if set_id[k] == ex:
                        set_id[k] = set_id[p0]
    print set_count
    #n = int(fin.readline())
    
    fout.write("Case #%d: %d\n" % (casenr+1, set_count))
    