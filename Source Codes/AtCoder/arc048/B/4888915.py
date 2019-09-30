import bisect
n = int(input())
info = [list(map(int,input().split()))+[i] for i in range(n)]

info = sorted(info)

info_rating = []
for i in range(n):
  info_rating.append(info[i][0])

memo = {}

for i in range(n):
  if info[i][0] not in memo:
    memo[info[i][0]] = {}
  if info[i][1] not in memo[info[i][0]]:
    memo[info[i][0]][info[i][1]] = 1
  else:
    memo[info[i][0]][info[i][1]] += 1
    
ans = []
for i in range(n):
  cnt_win = 0
  cnt_loose = 0
  cnt_even = 0
  
  cnt_win += bisect.bisect_left(info_rating,info_rating[i])
  
  if info[i][1] == 1:
    if 2 in memo[info[i][0]]:
      cnt_win += memo[info[i][0]][2]
    cnt_even += memo[info[i][0]][1] -1
    
  elif info[i][1] == 2:
    if 3 in memo[info[i][0]]:
      cnt_win += memo[info[i][0]][3]
    cnt_even += memo[info[i][0]][2] -1    
    
  elif info[i][1] == 3:
    if 1 in memo[info[i][0]]:
      cnt_win += memo[info[i][0]][1]
    cnt_even += memo[info[i][0]][3] -1
    
  cnt_loose = (n-1) - (cnt_win+cnt_even)
  ans.append([info[i][2],cnt_win,cnt_loose,cnt_even])
  #print(info[i][0],info[i][1],info[i][2],cnt_win,cnt_loose,cnt_even)
ans = sorted(ans)

for i in range(n):
  print(ans[i][1],ans[i][2],ans[i][3])