from numpy import*;B=searchsorted;a,b=split(int32(open(0).read().split()[1:]),2);c=0;h=l=2**29
while l:l//=2;y=sort(hstack((b%h-h,b%h)));c+=sum(B(y,h-a%h)-B(y,l-a%h))%2*l;h=l
print(c)