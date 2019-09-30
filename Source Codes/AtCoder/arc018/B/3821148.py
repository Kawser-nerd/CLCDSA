N = int(input())

# Area = abs(x1*y2 - y1*x2)/2
#???: lattice point
lattice = []

for i in range(N):
    x,y = (int(k) for k in input().split())
    lattice.append([x,y])
    
#Brute-force search  ????????????????????
triangles = 0 #initializing the number of triangles.
for i in range(N):
    for j in range(i+1,N):
        for k in range(j+1,N):
            x0 = lattice[i][0]
            y0 = lattice[i][1]
            x1 = lattice[j][0] - x0
            y1 = lattice[j][1] - y0
            x2 = lattice[k][0] - x0
            y2 = lattice[k][1] - y0
            
            doubleArea = abs(x1*y2 - y1*x2)
            #if doubleArea is dividable by 2, Area of an triangle will be integer.
            if doubleArea % 2 == 0 and doubleArea != 0:
                triangles += 1

print(triangles)