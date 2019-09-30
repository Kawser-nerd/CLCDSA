import math
N=int(input())
a=math.floor(N/7)
flag=False
for i in range(a+1):
    N2=N-i*7
    if N2%4!=0:
        continue
    else:
        flag=True
        break
if flag==True:
    print("Yes")
else:
    print("No")