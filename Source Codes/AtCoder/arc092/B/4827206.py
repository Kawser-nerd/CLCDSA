from numpy import*;B=searchsorted;a,b=loadtxt(open(0),'i4',skiprows=1);c=0;l=2**29
while l:h=l;l//=2;y=sort(hstack((b%h-h,b%h)));c+=sum(B(y,h-a%h)-B(y,l-a%h))%2*l
print(c)