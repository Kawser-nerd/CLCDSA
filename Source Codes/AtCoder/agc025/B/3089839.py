N,A,B,K=map(int,input().split())
P=998244353
def egcd(a, b):
    (x, lastx) = (0, 1)
    (y, lasty) = (1, 0)
    while b != 0:
        q = a // b
        (a, b) = (b, a % b)
        (x, lastx) = (lastx - q * x, x)
        (y, lasty) = (lasty - q * y, y)
    return (lastx, lasty, a)
def inv(x):
    return egcd(x,P)[0]
Fact=[0 for i in range(N+1)]
Finv=[0 for i in range(N+1)]
Fact[0]=1
Finv[0]=1
for i in range(1,N+1):
    Fact[i]=(i*Fact[i-1])%P
    Finv[i]=(Finv[i-1]*inv(i))%P
ans=0
def NC(k):
    tmp=(Finv[k]*Finv[N-k])%P
    return (Fact[N]*tmp)%P
for x in range(N+1):
    y=(K-x*A)//B
    if x*A+y*B==K and 0<=y<=N:
        ans+=(NC(x)*NC(y))%P
print(ans%P)