def intersect(p1,p2,p3,p4):
  t1 = (p1[0] - p2[0]) * (p3[1] - p1[1]) + (p1[1] - p2[1]) * (p1[0] - p3[0])
  t2 = (p1[0] - p2[0]) * (p4[1] - p1[1]) + (p1[1] - p2[1]) * (p1[0] - p4[0])
  t3 = (p3[0] - p4[0]) * (p1[1] - p3[1]) + (p3[1] - p4[1]) * (p3[0] - p1[0])
  t4 = (p3[0] - p4[0]) * (p2[1] - p3[1]) + (p3[1] - p4[1]) * (p3[0] - p2[0])
  return t1*t2<0 and t3*t4<0

ax,ay,bx,by = map(int,input().split())
point1 = [ax,ay]
point2 = [bx,by]
n = int(input())
info = [list(map(int,input().split())) for i in range(n)]
info.append(info[0])

count = 0
for i in range(n):
  if intersect(point1,point2,info[i],info[i+1]):
    count += 1

print(count//2+1)