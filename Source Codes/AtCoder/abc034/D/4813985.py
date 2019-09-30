n,k = map(int,input().split())

info = [list(map(int,input().split())) for i in range(n)]

used = [False]*n

ans_solution_g = 0
ans_salt_g = 0

for j in range(k):
  tmp_salution_g = 0
  tmp_salt_g = 0
  tmp_solution_p = 0
  tmp_i = 0
  for i in range(n):
    if used[i]:
      continue
    else:
      new_solution_g = ans_solution_g + info[i][0]
      new_salt_g = ans_salt_g + (info[i][0]*info[i][1])/100
      new_solution_p = (new_salt_g/new_solution_g)*100
      if new_solution_p > tmp_solution_p:
        tmp_solution_g = new_solution_g
        tmp_salt_g = new_salt_g
        tmp_solution_p = new_solution_p
        tmp_i = i
  used[tmp_i] = True
  ans_solution_g = tmp_solution_g
  ans_salt_g = tmp_salt_g

print(ans_salt_g/ans_solution_g*100)