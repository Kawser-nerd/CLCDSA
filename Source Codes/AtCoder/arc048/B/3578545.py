from operator import itemgetter
N = int(input())
A = []

for i in range(N):
  A.append([i] + list(map(int, input().split())) + [0,0,0])
  
A.sort(key=itemgetter(1,2),reverse=True)

prev_score = -1
for i in range(N):
  # ???????????
  if A[i][1] != prev_score:
    prev_score = A[i][1]
    cnt = 0
    start_i = i
    te = [0,0,0,0] # index0 is nonused
  else:
    # ??????????
    pass
  
  # ?????????
  cnt += 1    
  te[A[i][2]] += 1

  # ??peek??????????????
  if i + 1 >= N or A[i+1][1] != prev_score:
    end_i = i
    # ?????????????
    win, lose = N - end_i - 1, start_i
    for j in range(start_i, end_i+1):
      if A[j][2] == 1:
        A[j][3], A[j][4], A[j][5] = win + te[2], lose + te[3], te[1]-1
      elif A[j][2] == 2:
        A[j][3], A[j][4], A[j][5] = win + te[3], lose + te[1], te[2]-1
      else:
        A[j][3], A[j][4], A[j][5] = win + te[1], lose + te[2], te[3]-1
        
A.sort(key=itemgetter(0))
for i in range(N):
  print(A[i][3], A[i][4], A[i][5])