x,y=map(int,input().split())
x,y=x-1,y-1
mod=1000000007
c=1
for i in range(min(x,y)):
    c=(c*(x+y-i)*pow(i+1,mod-2,mod)%mod)
print(c%mod)