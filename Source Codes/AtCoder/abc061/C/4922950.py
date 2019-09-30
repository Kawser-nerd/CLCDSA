n,k = map(int,input().split())
li = [list(map(int, input().split())) for i in range(n)]
li.sort()

cnt=0
for i in range(n):
  cnt+=li[i][1]
  if cnt>=k:
    print(li[i][0])
    break