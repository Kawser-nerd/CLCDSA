x, y = (int(i) for i in input().split())
N = int(input())
point = [[int(i) for i in input().split()] for i in range(N)]
d_list = []
for i in range(N):
    a = point[i-1][0] - point[i][0]
    b = point[i-1][1] - point[i][1]
    d = (a*y - b*x - a*point[i][1] + b*point[i][0]) ** 2 / (a**2 + b**2)
    d_list.append(d)
print(min(d_list)**(1/2))