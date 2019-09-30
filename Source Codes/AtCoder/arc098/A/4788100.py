N = int(input())
S = list(input())
W_num = [] #??????????????????
w_num = 0

for i in range(N):
  W_num.append(w_num)
  if(S[i] == 'W'):
     w_num += 1
     
e_num = 0 #??????????????????
min_cost = float('inf')
for i in range(N):
   j = N-1-i
   tmp = W_num[j] + e_num
   min_cost = min(tmp,min_cost)
   if(S[j] == 'E'):
     e_num += 1
 
print(min_cost)