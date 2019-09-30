s = input()
t = input()
q =int(input())
info = [list(map(int,input().split())) for i in range(q)]

s_ruiseki = "X"
for i in range(len(s)):
  if s_ruiseki[-1] == "X":
    s_ruiseki = s_ruiseki+s[i]
  elif s_ruiseki[-1] != s[i]:
    s_ruiseki = s_ruiseki+"X"
  elif s_ruiseki[-1] == s[i] =="A":
    s_ruiseki = s_ruiseki+"B"
  else:
    s_ruiseki = s_ruiseki+"A"    

t_ruiseki = "X"
for i in range(len(t)):
  if t_ruiseki[-1] == "X":
    t_ruiseki = t_ruiseki+t[i]
  elif t_ruiseki[-1] != t[i]:
    t_ruiseki = t_ruiseki+"X"
  elif t_ruiseki[-1] == t[i] =="A":
    t_ruiseki = t_ruiseki+"B"
  else:
    t_ruiseki = t_ruiseki+"A"    

for i in range(q):
  if s_ruiseki[info[i][0]-1]  == "X":
    ans1 = s_ruiseki[info[i][1]]
  elif s_ruiseki[info[i][0]-1]  == "A":
    if s_ruiseki[info[i][1]] == "X":
      ans1 = "B"
    elif s_ruiseki[info[i][1]] == "B":
      ans1 = "A"
    elif s_ruiseki[info[i][1]] == "A":
      ans1 = "X"
  else:
    if s_ruiseki[info[i][1]] == "X":
      ans1 = "A"
    elif s_ruiseki[info[i][1]] == "B":
      ans1 = "X"
    elif s_ruiseki[info[i][1]] == "A":
      ans1 = "B"

  if t_ruiseki[info[i][2]-1]  == "X":
    ans2 = t_ruiseki[info[i][3]]
  elif t_ruiseki[info[i][2]-1]  == "A":
    if t_ruiseki[info[i][3]] == "X":
      ans2 = "B"
    elif t_ruiseki[info[i][3]] == "B":
      ans2 = "A"
    elif t_ruiseki[info[i][3]] == "A":
      ans2 = "X"  
  else:
    if t_ruiseki[info[i][3]] == "X":
      ans2 = "A"
    elif t_ruiseki[info[i][3]] == "B":
      ans2 = "X"
    elif t_ruiseki[info[i][3]] == "A":
      ans2 = "B"  
      
  if ans1 == ans2:
    print("YES")
  else:
    print("NO")