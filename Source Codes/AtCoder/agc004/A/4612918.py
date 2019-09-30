a,b,c=[int(i) for i in input().split()]
one=abs((a//2)*b*c-(a-a//2)*b*c)
two=abs(a*(b//2)*c-a*(b-b//2)*c)
thr=abs(a*b*(c//2)-a*b*(c-c//2))
print(min(one,two,thr))