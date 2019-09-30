a,b,c,d,e,f = map(int,input().split())
X1 = c-a
Y1 = d-b
X2 = e-a
Y2 = f-b
S = float(X1*Y2 - X2*Y1)/2

if S>0:
    print(S)
else:
    print(float(-S))