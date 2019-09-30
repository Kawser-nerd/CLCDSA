h,w=map(int,input().split());a=[input()for i in range(h)]
def che(i,j):
  global h,w,a
  if i==0:
    if a[i+1][j]=="#":return
  elif i==h-1:
    if a[i-1][j]=="#":return
  else:
    if a[i-1][j]=="#"or a[i+1][j]=="#":return
  print("No");exit()
for i in range(h):
  s=a[i]
  if s[:2]=="#.":che(i,0)
  if s[-2:]==".#":che(i,w-1)
  for j in range(w-2):
    if s[j]+s[j+1]+s[j+2]==".#.":che(i,j+1)
print("Yes")