import math
tx_b,ty_b,tx_a,ty_a,t,v = map(int,input().split())
n = int(input())
for i in range(n):
    x,y = map(int,input().split())
    g = math.sqrt((x-tx_b)**2+(y-ty_b)**2)+math.sqrt((tx_a-x)**2+(ty_a-y)**2)
    if g<=t*v:
        print("YES")
        break
else:
    print("NO")