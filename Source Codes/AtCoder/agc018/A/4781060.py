N,K = map(int,input().split())
A = [int(i) for i in input().split()]

def gcd(a,b):
    if a%b==0:
        return(b)
    else:
        return(gcd(b,a%b))
    
gcd_num = A[0]
for a in A:
    gcd_num = gcd(a,gcd_num)
    
if K%gcd_num==0 and K<=max(A):
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")