#n=int(input())
#d=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
#import numpy as np
#import math
#li=input().split()
#S=input()

lis=list(map(int,input().split()))
S=""
x=lis[2]-lis[0]
y=lis[3]-lis[1]
S+="U"*y
S+="R"*x
S+="D"*y
S+="L"*(x+1)
S+="U"*(y+1)
S+="R"*(x+1)
S+="D"
S+="R"
S+="D"*(y+1)
S+="L"*(x+1)
S+="U"
print(S)