s = input()

s_list = list(s)
s_set = set(s_list)
flag = 0
for n in s_set:
  if s.count(n) % 2 != 0:
    flag = 1
    
if flag == 0:
  print("Yes")
else:
  print("No")