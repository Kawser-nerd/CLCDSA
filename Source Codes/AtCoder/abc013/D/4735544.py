n,m,d = map(int,input().split())
a = list(map(int,input().split()))

rev_swap = [i for i in range(n)]
for i in range(m):
  rev_swap[a[i]-1],rev_swap[a[i]]  = rev_swap[a[i]],rev_swap[a[i]-1]
#  print(rev_swap)
  
swap = [0]*n
for i,num in enumerate(rev_swap):
  swap[num] = i
#print(swap)

memo_cycle = {}
memo_pos = {}
li = [[] for i in range(n)]
cnt_cycle = 0
  
for i in range(n):
  cnt_pos = 0
  num = i
  while True:
    if num in memo_cycle:
      break
    else:
      memo_cycle[num] = cnt_cycle
      memo_pos[num] = cnt_pos
      li[cnt_cycle].append(num)
      num = swap[num]
      cnt_pos += 1
  cnt_cycle += 1
#print(memo_cycle)
#print(memo_pos)
#print(li)

for i in range(n):
  len_cycle = len(li[memo_cycle[i]])
  pos = (d+memo_pos[i]) % len_cycle
  print(li[memo_cycle[i]][pos]+1)