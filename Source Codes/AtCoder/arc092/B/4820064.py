from numpy import*;B,I=searchsorted,lambda:int32(input().split());input();a,b=I(),I();c=0
for k in range(29):l=2**k;h=2*l;y=sort(hstack((b%h-h,b%h)));c+=sum(B(y,h-a%h)-B(y,l-a%h))%2*l
print(c)