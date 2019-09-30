#d=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
#import numpy as np
import math
#li=input().split()
#S=input()
#lis=list(map(int,input().split()))

n=int(input())

A=[0]
i=1
while i<=math.sqrt(n):
    if n%i==0:
        A.append(i)
    i+=1
B=[0]
s=[]
for i in range(len(A)-1):
    j=int(n/A[i+1])
    B.append(j)
    a=len(str(A[i+1]))
    b=len(str(B[i+1]))
    s.append(max(a,b))
ans=min(s)
print(ans)