N = int(input())
sum_a = 0
num = 10e10
for i in range(N):
  a,b = list(map(int,input().split()))
  sum_a += a
  if a > b:
    num = min(num,b)

if num == 10e10:
  print(0)
else:
  print(sum_a-num)