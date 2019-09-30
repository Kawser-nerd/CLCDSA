#d=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
#import numpy as np
import math
#n=int(input())
#li=input().split()
#S=input()

n=int(input())
lis=list(map(int,input().split()))

l=[0,0,0,0,0,0,0,0,0]

for i in range(n):
    a=math.floor(lis[i]/400)
    if a<8:
        l[a]=1
    else:
        l[-1]+=1

if sum(l[:8])==0:
    print(1,l[8])
else:
    print(sum(l[:8]),sum(l))