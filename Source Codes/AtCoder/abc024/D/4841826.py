a=int(input())
b=int(input())
c=int(input())

mod=10**9+7
i=pow((b+c)*a-b*c,mod-2,mod)
r=(b-a)*c*i%mod
c=(c-a)*b*i%mod

print(r,c)