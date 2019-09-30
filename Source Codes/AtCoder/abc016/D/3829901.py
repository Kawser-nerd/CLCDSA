AX,AY,BX,BY = map(int,input().split())
N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]
src.append(src[0])

def cross_prod(ax,ay,bx,by,px,py):
  v1x = bx - ax
  v1y = by - ay
  v2x = px - ax
  v2y = py - ay
  return v1x * v2y - v1y * v2x

def is_crossing(x11,y11,x12,y12,x21,y21,x22,y22):
  l1_p21 = cross_prod(x11,y11,x12,y12,x21,y21)
  l1_p22 = cross_prod(x11,y11,x12,y12,x22,y22)
  l2_p11 = cross_prod(x21,y21,x22,y22,x11,y11)
  l2_p12 = cross_prod(x21,y21,x22,y22,x12,y12)
  return l1_p21 * l1_p22 < 0 and l2_p11 * l2_p12 < 0

ans = 0
for (x1,y1),(x2,y2) in zip(src, src[1:]):
    if is_crossing(AX,AY,BX,BY,x1,y1,x2,y2):
        ans += 1
print(ans//2 + 1)