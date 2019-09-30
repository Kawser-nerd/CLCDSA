class Factorial:
    def __init__(self,n,mod):
        self.f=[1]
        for i in range(1,n+1):
            self.f.append(self.f[-1]*i%mod)
        self.i=[pow(self.f[-1],mod-2,mod)]
        for i in range(1,n+1)[::-1]:
            self.i.append(self.i[-1]*i%mod)
        self.i.reverse()
    def factorial(self,i):
        return self.f[i]
    def ifactorial(self,i):
        return self.i[i]
    def comb(self,n,k):
        return self.f[n]*self.i[n-k]%mod*self.i[k]%mod
mod=10**9+7
h,w,a,b=map(int,input().split())
f=Factorial(h+w,mod)
ans=0
for i in range(b,w):
    ans=(ans+f.comb(h-a-1+i,i)*f.comb(a-1+w-i-1,w-i-1))%mod
print(ans)