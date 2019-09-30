from math import*
from collections import*
def factorize(n):
    b = 2
    fct = []
    while b * b <= n:
        while n % b == 0:
            n //= b
            fct.append(b)
        b += 1
    if n > 1:
        fct.append(n)
    return fct

def fil(num):
    return len([1 for k,v in l.items() if v>=num-1])

l=[]
for i in range(2,int(input())+1):
    l.extend(factorize(i))
    
l=Counter(l)
#print(l)

print(fil(75)+fil(25)*(fil(3)-1)+fil(15)*(fil(5)-1)+fil(5)*(fil(5)-1)*(fil(3)-2)//2)