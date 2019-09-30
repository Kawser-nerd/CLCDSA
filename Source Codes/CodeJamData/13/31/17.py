import math
T = int(raw_input())

consonants = "bcdfghjklmnpqrstvwxyz"

def check(s, n):
    L = len(s)
    i = 0
    num_conse_cons = 0
    while i < L:
        if s[i] not in consonants:
            num_conse_cons = 0
        else:
            num_conse_cons += 1
            if num_conse_cons >= n:
                return True
        i += 1
    
    return False
             
            
for t in range(T):
    line = [i.strip() for i in raw_input().split()]
    name = line[0]
    n = int(line[1])
    
    A = [0 for i in range(len(name))] # No good substrings ends at i th index
    B = [0 for i in range(len(name))]
    
    for i in range(0, len(name)):
        if name[i] in consonants:
            if i == 0:
                B[i] = 1
            else:
                B[i] = B[i-1] + 1
        else:
            B[i] = 0

    if n == 1 and name[i] in consonants:
        A[0] = 1

    for i in range(1, len(name)):
        if B[i] < n:
            A[i] = A[i-1]
        else:
            A[i] = i - n + 2

    #print A
    #print B

    res = 0
    for i in range(len(name)):
        res += A[i]

    print 'Case #%s: %s' % (t+1, res)
