import sys
from collections import Counter,defaultdict
import itertools

def bf(C,J):
    n=len(C)
    def make_choices(C):
        Cs=[]
        for c in range(10**n):
            c_s = str(c).zfill(n)
            for x,y in zip(c_s,C):
                if y=='?':
                    continue
                if x!=y:
                    break
            else:
                Cs.append(c_s)
        return Cs
    Cs=make_choices(C)
    Js=make_choices(J)
    A=[]
    for c in Cs:
        for j in Js:
            c_val = int(''.join(c))
            j_val = int(''.join(j))
            A.append( (abs(c_val-j_val),c_val,j_val,''.join(c),''.join(j)) ) 
    _,_,_,c,j=min(A)
    return c+' '+j

def go(C,J):
    n=len(C)
    assert len(J)==n
    A=[] # Possible solutions, abs diff,c,j as numbers
    # Choose number of initial digits to match
    for num_match in range(n+1):
        c=['']*n
        j=['']*n
        for i in range(num_match):
            if C[i]=='?':
                if J[i]=='?':
                    c[i]='0'
                    j[i]='0'
                else:
                    c[i]=J[i]
                    j[i]=J[i]
            else:
                c[i]=C[i]
                j[i]=C[i]
                if J[i]!='?' and J[i]!=C[i]:
                        break # No match possible
        else:
            if num_match==n:
                # All match, we are done
                A.append( (0,0,0,''.join(c),''.join(j)) )
                break
            # Now try all choices for the central digits
            if C[num_match]=='?':
                Cs='0123456789'
            else:
                Cs=C[num_match]
            if J[num_match]=='?':
                Js='0123456789'
            else:
                Js=J[num_match]
            for xc in Cs:
                for xj in Js:
                    c[num_match] = xc
                    j[num_match] = xj
                    c_val = int(''.join(c))
                    j_val = int(''.join(j))
                    # Fill remaining based on if we are higher or lower
                    for i in range(num_match+1,n): 
                        if C[i]=='?':
                            c[i] = '9' if c_val<j_val else '0'
                        else:
                            c[i] = C[i]
                        if J[i]=='?':
                            j[i] = '9' if j_val<c_val else '0'
                        else:
                            j[i] = J[i]
                    c_val = int(''.join(c))
                    j_val = int(''.join(j))
                    A.append( (abs(c_val-j_val),c_val,j_val,''.join(c),''.join(j)) )  
    _,_,_,c,j=min(A)
    v = c+' '+j
    #assert(v==bf(C,J))
    return v

#print 'Remove this line'
#sys.stdin=open('datab.txt')
#sys.stdin=open(r'c:\Users\Peter\Downloads\B-small-attempt0.in')

T=input()
for t in range(1,T+1):
    C,J=raw_input().split()
    
    print "Case #{}: {}".format(t,go(C,J))
