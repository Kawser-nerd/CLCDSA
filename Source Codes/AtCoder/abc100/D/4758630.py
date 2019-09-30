n,m = map(int,input().split())
info = [[0]+list(map(int,input().split())) for i in range(n)]

ans = 0
for oishi in range(2):
  for kirei in range(2):
    for ninki in range(2):
      for i in range(n):
        info[i][0] = ((-1)**kirei)*info[i][1] + ((-1)**oishi)*info[i][2] + ((-1)**ninki)*info[i][3]
      info = sorted(info,reverse = True)
      ans_kirei = 0
      ans_oishi = 0
      ans_ninki = 0
      for i in range(m):
        ans_kirei += ((-1)**kirei)*info[i][1]
        ans_oishi += ((-1)**oishi)*info[i][2]
        ans_ninki += ((-1)**ninki)*info[i][3]
      ans = max(ans,ans_kirei + ans_oishi + ans_ninki)
print(ans)