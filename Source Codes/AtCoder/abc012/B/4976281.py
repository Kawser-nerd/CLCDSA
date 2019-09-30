n=int(input())
x=n/3600
if x>=1:
    a=int(x)
else:
    a=0
if (n%3600)/60>=1:
    b=int((n%3600)/60)
else:
    b=0
c=(n%3600)%60
if len(str(a))==1:
    a="0"+str(a)
if len(str(b))==1:
    b="0"+str(b)
if len(str(c))==1:
    c="0"+str(c)
print(str(a)+":"+str(b)+":"+str(c))