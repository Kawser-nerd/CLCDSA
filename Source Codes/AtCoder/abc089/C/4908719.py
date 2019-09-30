N = int(input())
S = [input() for i in range(N)]
S_march = []
MARCH = ["M", "A", "R", "C", "H"]

cmb = []
ans = 0

N_march = [0]*5

for Si in S:
  for j in range(5):
    if Si[:1] == MARCH[j]:
      N_march[j] += 1

for i in range(2**5):
  check = [False]*5
  for j in range(5):
    if (i>>j) & 1:
      check[j] = True
  if check.count(True) == 3:
    cmb.append(check)

for i in cmb:
  tmp_list = []
  for j in range(5):
    if i[j]:
      tmp_list.append(N_march[j])
  ans += tmp_list[0]*tmp_list[1]*tmp_list[2]
  
print(ans)
      
      
#for i in range(2*N):
#  for j in range(N):
#    if (i>>j) & 1:
#      if S[j][:1] in MARCH:
#        check[j] = True
#        MARCH.pop(S[j][:1])
#  if check.count(True) == 3:
#    ans += 1
#print(ans)