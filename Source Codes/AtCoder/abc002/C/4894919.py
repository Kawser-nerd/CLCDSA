import math
xa,ya,xb,yb,xc,yc = map(int,input().split())

a = math.sqrt((xa-xb)**2+(ya-yb)**2)
b = math.sqrt((xb-xc)**2+(yb-yc)**2)
c = math.sqrt((xc-xa)**2+(yc-ya)**2)

s = (a+b+c)/2
S = math.sqrt(s*(s-a)*(s-b)*(s-c))
print(str(S) + "\n")