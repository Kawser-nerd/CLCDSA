import bisect
n,m,x=map(int,input().split())
A=[int(x) for x in input().split()]
i=bisect.bisect_left(A,x)
j=bisect.bisect_right(A,x)
print(min(i,m-j))