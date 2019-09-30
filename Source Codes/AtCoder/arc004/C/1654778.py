from fractions import Fraction
#x/y??????m?n?n/2
x,y=map(int,input().split("/"))
i=1
xdivy=Fraction(x,y)
nkari=2*x//y
nkari2=2*x//y+1
flag=False
sumkari=nkari*(nkari+1)//2
sumkari2=nkari2*(nkari2+1)//2
#print(xdivy)
anskari1=Fraction(nkari*(nkari+1),2)-xdivy*nkari
anskari2=Fraction(nkari2*(nkari2+1),2)-xdivy*nkari2
flag=False
if anskari1.denominator==1 and anskari1!=0 and nkari!=0:
    flag=True
    print(nkari,anskari1)
if anskari2.denominator==1 and anskari2!=0 and nkari2!=0:
    flag=True
    print(nkari2,anskari2)
if not flag:
    print("Impossible")