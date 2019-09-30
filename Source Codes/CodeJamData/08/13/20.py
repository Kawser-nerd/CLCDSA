

from decimal import *
D = Decimal
C = getcontext()


def modpow(x, p, m):
    if p==1:
        return x%m
    
    if p&1:
        return (x*modpow(x, p-1, m))%m
    
    else:
        return modpow((x*x)%m, p/2, m) 
    

def main():
    C.prec = 10000
    
    T = int(raw_input())
    for t in xrange(T):
        N = int(raw_input())
        
        
        X = D('3') + C.sqrt(D('5'))
        X = modpow(X, N, 1000)
        
        
        
        
        
        #print X
        r = int(X) % 1000
        print 'Case #%d: %03d' % (t+1, r)
        
        

def do(A, B, N):
    
    if N==1:
        return D(A)+D(B).sqrt()
    
    if N&1:
        return do(A, B, N-1) * do(A, B, 1)
        
    else:
        return do(A*A + B, ((2*A)**2)*B, N/2)
    
    
    


def main2():
    C.prec = 1000
    
    T = int(raw_input())
    for t in xrange(T):
        N = int(raw_input())
        
        
        X = do(3, 5, N)
        
        r = int(X) % 1000
        print 'Case #%d: %03d' % (t+1, r)
        
        
        
if __name__ == '__main__':
    main2()
    
