q,h,s,d = map(int,input().split())
n = int(input())
one = min(4*q,2*h,s)
if n%2==0:
    print(min(d*(n//2),n*one))
else:
    print(min(d*(n//2)+one,n*one))