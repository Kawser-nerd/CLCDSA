a=[list(map(int,input().split()))for _ in range(3)]
for i in range(2):
  if not a[0][i]-a[0][i+1]==a[1][i]-a[1][i+1]==a[2][i]-a[2][i+1]:print("No");exit()
for i in range(2):
  if not a[i][0]-a[i+1][0]==a[i][1]-a[i+1][1]==a[i][2]-a[i+1][2]:print("No");exit()
print("Yes")