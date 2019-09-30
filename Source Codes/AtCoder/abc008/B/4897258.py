n = int(input())
dic = {}
for i in range(n):
  tmp = input()
  if tmp in dic.keys():
    
    dic[tmp] += 1
  else:
    dic[tmp] = 1

for name in dic.keys():
  if dic[name] == max(dic.values()):
    print(name)
    break