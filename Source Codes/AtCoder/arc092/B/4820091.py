from numpy import*;B=searchsorted;a,b=split(int32(open(0).read().split()[1:]),2);c=0
for k in range(29):l=2**k;h=2*l;y=sort(hstack((b%h-h,b%h)));c+=sum(B(y,h-a%h)-B(y,l-a%h))%2*l
print(c)