import math
n = int(input())
a = [int(i) for i in input().split()]
su = 0
cnt = 0
for i in a:
  if i != 0:
    su += i
    cnt += 1
print(math.ceil(su / cnt))