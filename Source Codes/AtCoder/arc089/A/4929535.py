N=int(input())
travel=[[0,0,0]]+[ list(map(int,input().split(' '))) for i in range(N) ]
ans='Yes'
for i in range(N):
  dt = travel[i+1][0]-travel[i][0]
  dx = abs(travel[i+1][1]-travel[i][1])
  dy = abs(travel[i+1][2]-travel[i][2])
  if dx+dy<=dt and (dx+dy)%2==dt%2:
    continue
  else:
    ans='No'
    break
print(ans)