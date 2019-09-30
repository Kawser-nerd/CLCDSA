N = int(input())
words = [input() for _ in range(N)]

flag = False
for i in range(N-1):
  if words[i][-1] != words[i+1][0]:
    flag = True
  else:
    continue

if len(words) != len(set(words)):
  print("No")
elif flag == True:
  print("No")
else:
  print("Yes")