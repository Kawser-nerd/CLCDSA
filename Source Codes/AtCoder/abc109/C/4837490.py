import math

def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a


N,X = map(int,input().split())
x = input().split()
xls = []
 
for n in range(0,N):
    xls.append(int(x[n]))
 
xls.append(X)
xls.sort(reverse = True)
 
tousa = []
 
for n in range(0,N):
    tousa.append(xls[n]-xls[n+1])
 
if len(tousa) == 1:
    print(tousa[0])
    exit()
gcdd = gcd(tousa[0],tousa[1])
 
for n in range(0,N):
    gcdd = gcd(gcdd,tousa[n])
    
print(gcdd)