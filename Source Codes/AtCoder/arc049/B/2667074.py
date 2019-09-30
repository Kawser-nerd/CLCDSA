n = int(input())
p = [[int(i) for i in input().split()] for i in range(n)]
def com(n):
	xa,xb,ya,yb = p[0][0]-n/p[0][2],p[0][0]+n/p[0][2],p[0][1]-n/p[0][2],p[0][1]+n/p[0][2]
	for i,j,k in p[1:]: xa,xb,ya,yb = max(xa,i-n/k),min(xb,i+n/k),max(ya,j-n/k),min(yb,j+n/k)
	return xa<xb and ya<yb
lo,hi = 0,10**9
for _ in range(100):
	mid = (lo+hi)/2
	if com(mid): hi = mid
	else: lo = mid
print(hi)