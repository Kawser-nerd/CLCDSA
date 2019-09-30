p=float(input())
f=lambda x:x+p*2**(-2*x/3)
a,b,d=0,100,0
while a+1e-9<b and d<10**5:
    c=(a+b)/2
    if f(a)>f((a+c)/2)>f(c):a=(a+c)/2
    if f(b)>f((b+c)/2)>f(c):b=(b+c)/2
    d+=1
print(f((a+b)/2))