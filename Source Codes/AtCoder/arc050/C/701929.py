#!/usr/bin/python3

# x^y % m
#def mod_pow(x, y, m):
#    if y==0:     return 1
#    elif y==1:   return x%m
#    elif x==0:   return 0
#    elif y%2==1: return (x*mod_pow(x,y-1,m))%m
#    elif y%2==0:
#        t = mod_pow(x,y/2,m)
#        return (t*t)%m

# ( 1 + a + a^2 + ... + a^(n-1) ) % m
def modpowsum(a,n,m):
    if n==0:      return 0
    elif n%2==1:  return (1+a*modpowsum(a,n-1,m))%m
    else:
        t = modpowsum(a,n//2,m)
        return (t + (t * pow(a,n//2,m))%m ) %m

def gcd(x,y):
    if x>y:  x,y=y,x
    if x==0: return y
    else:    return gcd(y%x,x)

a,b,m = map(int,input().split())
g = gcd(a,b)
t1 = modpowsum(pow(10,g,m),a//g,m)
t2 = modpowsum(10,b,m)
print((t1*t2)%m)