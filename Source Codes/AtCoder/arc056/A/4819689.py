a,b,k,l = map(int,input().split())
m = k//l
print(b*m+min(b,a*(k-l*m)))