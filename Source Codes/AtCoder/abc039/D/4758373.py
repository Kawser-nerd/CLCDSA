h,w = map(int,input().split())
s = ["#"*(w+2)]+["#"+input()+"#" for i in range(h)]+["#"*(w+2)]
old_s = [["."]*(w+2) for i in range(h+2)]

for i in range(1,h+1):
  for j in range(1,1+w):
    if s[i-1][j-1:j+2] == "###" and \
       s[i][j-1:j+2]   == "###" and \
       s[i+1][j-1:j+2] == "###":
          old_s[i][j] ="#"

new_s = [["."]*(w+2) for i in range(h+2)] 
for i in range(1,h+1):
  for j in range(1,1+w):
    if old_s[i][j] == "#":
      for k in [-1,0,1]:
        for l in [-1,0,1]:
          new_s[i+k][j+l] = "#"

for i in range(1,h+1):
  if "".join(new_s[i][1:1+w]) != s[i][1:1+w]:
    print("impossible")
    break
else:
  print("possible")
  for i in range(1,h+1):
    print("".join(old_s[i][1:1+w]))