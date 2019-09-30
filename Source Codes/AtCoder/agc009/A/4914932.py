n = int(input())
cnt = 0
a = [list(map(int, input().split())) for _ in range(n)]
a.reverse()
cnt = 0
for i in range(n) :
  if((a[i][0] + cnt) % a[i][1] != 0) :
    cnt += a[i][1] - ((a[i][0] + cnt) % a[i][1])
print(cnt)