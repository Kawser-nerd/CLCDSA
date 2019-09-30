n=int(input())
points=[input().split() for i in range(0, n)]
sorted(points)
max_d = 0
import math
for i in range(n):
    for j in range(i,n):
        
        deltax= int(points[i][0]) - int(points[j][0])
        deltay= int(points[i][1]) - int(points[j][1])
        d = math.sqrt(deltax**2 + deltay**2)
        if max_d < d:
            max_d = d
print(max_d)