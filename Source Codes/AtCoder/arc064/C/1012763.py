xs,ys,xt,yt=list(map(int,input().split()))
N=int(input())
a=[]
for i in range(N):
	a.append(list(map(int,input().split())))

# xs,ys,xt,yt=[-1000000000, -1000000000, 1000000000, 1000000000]
# N=1
# a=[[-1000000000, 1000000000, 1]]

class Dijkstra(object):
	"""
	???????,(N^2)
	?????:distance(list),prev(list),size(int)
	distancemap[i][j]->Distance of edge i to j
	"""
	def __init__(self, distancemap, start):
		self.start=start
		self.size=len(distancemap)
		self.distance=[float("inf") for x in range(self.size)]
		self.distance[start]=0
		self.prev=[0 for x in range(self.size)]
		self.prev[start]=-1
		yet=list(range(self.size))
		yet.remove(start)
		now=start
		while(yet!=[]):
			nearest_num=0
			nearest_dis=float("inf")
			for i in yet:
				total_dis=distancemap[now][i]+self.distance[now]
				self.distance[i]=min(total_dis, self.distance[i])
				if self.distance[i]<=nearest_dis:
					nearest_dis=self.distance[i]
					nearest_num=i
			yet.remove(nearest_num)
			self.prev[nearest_num]=now
			now=nearest_num

	def route(self,goal):
		route=[]
		while(True):
			route.append(self.prev[goal])
			goal=self.prev[goal]
			if goal==self.start:
				break
		route.reverse()
		return(route)

import math
def solve(xs,ys,xt,yt,N,a):
	a.insert(0,[xs,ys,0])
	a.append([xt,yt,0])
	def distance(i,j):
		x1=a[i][0]
		y1=a[i][1]
		r1=a[i][2]
		x2=a[j][0]
		y2=a[j][1]
		r2=a[j][2]
		d=math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))-r1-r2
		if d<0:
			d=0
		return(d)
	distancemap=[[0 for x in range(N+2)] for x in range(N+2)]
	for i in range(N+2):
		for j in range(N+2):
			if i>j:
				distancemap[i][j]=distancemap[j][i]
			else:
				distancemap[i][j]=distance(i,j)

	d=Dijkstra(distancemap, 0)
	return(d.distance.pop())

print(solve(xs, ys, xt, yt, N, a))