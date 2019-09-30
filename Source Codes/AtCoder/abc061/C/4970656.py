#d=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
#import numpy as np
#import math
#n=int(input())
#li=input().split()
#n=int(input())
#S=input()

ab=[0]*(10**5+1)
lis=list(map(int,input().split()))
for i in range(lis[0]):
    t=list(map(int,input().split()))
    ab[t[0]]+=t[1]

ans=0
i=1
count=0
while count<lis[1]:
    count+=ab[i]
    ans=i
    i+=1

print(ans)