a,b,k,l=map(int,input().split())
n=k//l
m=k-n*l
print(min(b*(n+1),a*m+b*n))