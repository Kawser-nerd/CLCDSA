n = int(input())
s = [input() for i in range(n)]
res = 0
temp = 0
for i in set(s):
    temp = 0
    for j in s:
        if i==j:
            temp += 1
    res = max(res,temp)
for i in set(s):
    if s.count(i)==res:
        print(i)
        exit()