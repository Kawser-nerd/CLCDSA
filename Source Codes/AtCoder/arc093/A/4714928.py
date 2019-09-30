N = int(input())
A = [int(_) for _ in input().split()] + [0]
dist = []
tmp = 0
alldist = 0

for i in A:
    dist.append(i-tmp)
    tmp = i

for i in dist:
     alldist += abs(i)

for i in range(N):
    print(alldist - (abs(dist[i])+abs(dist[i+1])-abs(dist[i]+dist[i+1])))