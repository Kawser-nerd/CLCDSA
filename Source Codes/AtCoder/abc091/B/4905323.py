N =int(input())
l1 =[input() for i in range(N)]
M =int(input())
l2 =[input() for i in range(M)]
dic = {'':0}
for v in (l1 + l2):
    dic[v] = l1.count(v) - l2.count(v)
print(max(dic.values()))