import sys
input = sys.stdin.readline

N,M = (int(i) for i in input().split())
dic = {}
cnt = 0
pos = 0
for i in range(M):
  a,b = map(int,input().split())
  if b not in dic or dic[b] < a:
    dic[b] = a

for j in sorted(dic.keys()):
  if dic[j] >= pos:
    cnt += 1
    pos = j
print(cnt)