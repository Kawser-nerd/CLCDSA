n = int(input())
a = [int(i) for i in input().split()]

dic = {}
for idx, x in enumerate(a):
    dic[x] = idx+1

for x in sorted(a, reverse=True):
    print(dic[x])