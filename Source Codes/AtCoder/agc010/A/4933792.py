N = int(input())
A = list(map(int,input().split()))
count_odd,count_even = 0,0
judge = 0

for a in A:
  if(a%2 == 0): count_even += 1
  else: count_odd += 1
    
if(count_odd%2 == 0):
  judge = 1

if(judge == 1): print('YES')
else: print('NO')