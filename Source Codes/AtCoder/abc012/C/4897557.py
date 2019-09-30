n = int(input())
dic = {}
for i in range(1,10):
  for j in range(1,10):
    if i * j in dic.keys():
      dic[i * j].append(str(i)+" x "+str(j))
    else:
      dic[i * j] = [str(i)+" x "+str(j)]
ls = sorted(dic[2025 - n])
for i in ls:
  print(i)