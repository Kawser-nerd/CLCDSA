iipt=lambda:int(input())
miipt=lambda:list(map(int, input().split()))
from pprint import pprint
n=iipt()
hs=[miipt() for i in range(n)]

a=0
b=int(1e15)

while b-a>1: # ????~~~???
    c=(a+b)//2 # ??c???????
    tl=sorted([(c-h)//s for h,s in hs]) # ?????????
    if all(t<=i for t,i in enumerate(tl)):
        # ???
        b=c
        #print("b")
    else:
        a=c
        #print("a")

print(b)