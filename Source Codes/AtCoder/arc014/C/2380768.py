from collections import Counter
n = int(input())
s = list(str(input()))
lis = []
li = ["R","G","B"]
for i in range(3):
  try:
    lis.append((s.count(li[i]))%2)
  except:
    lis.append(0)

print(sum(lis))