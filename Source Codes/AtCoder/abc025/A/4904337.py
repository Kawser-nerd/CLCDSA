s = input()
n = int(input())
s1 = s
dic = {}
cnt = 1
for i in range(5):
  for j in range(5):
    dic[cnt] = s[i]+s[j]
    cnt += 1
print(dic[n])