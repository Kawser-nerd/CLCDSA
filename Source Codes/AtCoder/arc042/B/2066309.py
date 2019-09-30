import numpy as np
from numpy import*

# ? a, b ??????? c ?????? abs(cross(u,v) / dist(a,b))
def distance_l(a,b,c):
	u = np.array([b[0] - a[0], b[1] - a[1]])
	v = np.array([c[0] - a[0], c[1] - a[1]])
	L = abs(cross(u,v) / linalg.norm(u))
	return L

# ? a, b ??????? c ??????
def distance_seg(a,b,c):
	u = np.array([b[0] - a[0], b[1] - a[1]])
	v = np.array([c[0] - a[0], c[1] - a[1]])
	w = np.array([c[0] - b[0], c[1] - b[1]])
	res = 0
	if dot(u,v) <= 0:
		res = linalg.norm(v) # abs(a-c)
	elif dot(-u,w) <= 0:
		res = linalg.norm(w) # abs(b-c)
	else:
		res = distance_l(a,b,c)
	return res

x,y = map(int,input().split())
N = int(input())
px = [0]*N
py = [0]*N
for i in range(N):
	px[i],py[i] = map(int,input().split())

res = float('inf')
u = np.array([x,y])
for i in range(N):
	j = (i + 1) % N
	v = np.array([px[i],py[i]])
	w = np.array([px[j],py[j]])
	curr = distance_seg(v,w,u)
	res = min(res, curr)

print(res)