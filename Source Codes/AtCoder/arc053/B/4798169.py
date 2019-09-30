s = input()

memo = {}
for i in s:
  if i not in memo:
    memo[i] = 1
  else:
    memo[i] += 1

cnt_odd = 0
cnt_even = 0
for i in memo:
  if memo[i] %2 == 1:
    cnt_odd += 1
  cnt_even += memo[i]//2

if cnt_odd ==0:
  print(cnt_even*2)
else:
  print(2*(cnt_even//cnt_odd) + 1)