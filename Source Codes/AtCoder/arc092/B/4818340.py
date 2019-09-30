from numpy import*;B,I=searchsorted,lambda:int32(input().split());input();a,b=I(),I();c=0
for k in range(29):l=2**k;h=l*2;x,y=a%h,sort(b%h);y=hstack((y-h,y));c+=sum(B(y,h-x)-B(y,l-x))%2*l
print(c)