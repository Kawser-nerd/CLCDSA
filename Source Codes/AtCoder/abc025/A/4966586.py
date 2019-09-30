s = input()
n = int(input())
dic = []
for i in range(5):
  for j in range(5):
    dic.append(s[i]+s[j])

print(dic[n-1])