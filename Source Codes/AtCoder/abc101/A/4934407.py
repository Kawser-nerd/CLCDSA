s = input()
s_list = list(s)
count = 0
for i in range(len(s_list)):
  if s_list[i] == '+':
    count += 1
  elif s_list[i] == '-':
    count -= 1
print(count)