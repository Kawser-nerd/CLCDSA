N=int(input().strip())
t=[]
x=[]
y=[]
for i in range(N):
    tm, xm, ym=map(int,input().strip().split(' '))
    t.append(tm)
    x.append(xm)
    y.append(ym)
tn=0
xn=0
yn=0
fl=True
for i in range(N):
    tn=t[i]-tn
    xn=x[i]-xn
    yn=y[i]-yn
    #print(tn,xn,yn)
    if tn<abs(xn)+abs(yn) or tn%2!=(xn+yn)%2:
        fl=False
        break
if fl:
    print('Yes')
else:
    print('No')