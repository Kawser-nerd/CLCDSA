def intersect(p1, p2, p3, p4):
    tc1 = (p1[0] - p2[0]) * (p3[1] - p1[1]) + (p1[1] - p2[1]) * (p1[0] - p3[0])
    tc2 = (p1[0] - p2[0]) * (p4[1] - p1[1]) + (p1[1] - p2[1]) * (p1[0] - p4[0])
    td1 = (p3[0] - p4[0]) * (p1[1] - p3[1]) + (p3[1] - p4[1]) * (p3[0] - p1[0])
    td2 = (p3[0] - p4[0]) * (p2[1] - p3[1]) + (p3[1] - p4[1]) * (p3[0] - p2[0])
    return tc1*tc2<0 and td1*td2<0
a,b,c,d = map(int,input().split())
a = [[a,b],[c,d]]
n = int(input())
x = []
for i in range(n):
  c,d = map(int,input().split())
  x.append([c,d])
x = x + [x[0]]
ans = 0
for i in range(n):
  if intersect(a[0],a[1],x[i],x[i+1]):
    ans += 1
print(ans//2+1)