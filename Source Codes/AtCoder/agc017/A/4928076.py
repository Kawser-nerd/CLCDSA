N,P=map(int,input().split())
A=list(map(int,input().split()))

ODD=0
EVE=0

for i in range(N):
    if A[i]%2==1:
        ODD+=1
    else:
        EVE+=1
        
def cmb(n, r, mod):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod

mod = 10**15+7 #?????
N = 10**5
g1 = [1, 1] # ?????
g2 = [1, 1] #??????
inverse = [0, 1] #?????????????

for i in range( 2, N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

if P==1:
    O=0
    E=1
    for i in range(EVE):
        E+=cmb(EVE,i,mod)
        E%=(10**15+7)
        
    for i in range((ODD+1)//2):
        O+=cmb(ODD,1+2*i,mod)
        
        
    ans=(E*O)%(10**15+7)
    print(ans)
else:
    O=0
    E=1
    for i in range(EVE):
        E+=cmb(EVE,i,mod)
        E%=(10**15+7)
        
    for i in range((ODD)//2+1):
        O+=cmb(ODD,2*i,mod)
        #print(O)
        
    ans=(E*O)%(10**15+7)
    print(ans)