import bisect
from collections import defaultdict
r,c,k = map(int,input().split())
n = int(input())

cnt_row =[0 for i in range(r)]
cnt_col = [0 for i in range(c)]

pos_ame = []
for i in range(n):
  pos_row,pos_col = map(int,input().split())
  cnt_row[pos_row-1] += 1
  cnt_col[pos_col-1] -= 1
  pos_ame.append([pos_row-1,pos_col-1])

srtd_cnt_row = sorted(cnt_row)
srtd_cnt_col = sorted(cnt_col)

ans = 0
left_r = 0
left_c = bisect.bisect_right(srtd_cnt_col,-(k+1))

for i in range(k+1):
  right_r = bisect.bisect_right(srtd_cnt_row,i,left_r)
  right_c = bisect.bisect_right(srtd_cnt_col,-k+i,left_c)
  ans = ans + (right_r-left_r)*(right_c-left_c)
  left_r = right_r
  left_c = right_c

for i,j in pos_ame:
  if cnt_row[i] - cnt_col[j] == k:
    ans -= 1
  elif cnt_row[i] - cnt_col[j] == k+1:
    ans += 1

print(ans)