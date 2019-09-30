#copy
h,w = (int(i) for i in input().split())
l = [list(input()) for _ in range(h)]
ans = [["#" for _ in range(w)] for _ in range(h)]

ans2 = [["." for _ in range(w)] for _ in range(h)]

for i in range(h):
  for j in range(w):
    if l[i][j] == '.':
      for dx in [-1,0,1]:
       for dy in [-1,0,1]:
        if 0 <= j+dx<w and 0<=i+dy<h:
          ans[i+dy][j+dx] = "."
#???          
for i in range(h):
  for j in range(w):
    for dy in [-1,0,1]:
      for dx in [-1,0,1]:
        if 0<=j+dx<w and 0<=i+dy<h and ans[i+dy][j+dx]=="#":
          ans2[i][j]="#"  

if l==ans2:
  print('possible')
  for i in ans:
    print("".join(i))
else:
  print('impossible')