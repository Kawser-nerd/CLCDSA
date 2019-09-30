p = list(map(int, input().split()))
print(0.5*abs((p[0]-p[4])*(p[3]-p[5])-(p[2]-p[4])*(p[1]-p[5])))