mod=10**9+7
A=int(input())
B=int(input())
C=int(input())
def INV(i):
    return pow(i,mod-2,mod)
print(((C*B-C*A)*INV(A*B-C*B+C*A))%mod,((B*C-B*A)*INV(A*C-B*C+B*A))%mod)