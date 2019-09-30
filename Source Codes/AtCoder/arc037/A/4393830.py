n=int(input())
m=list(map(int,input().split()))
sum_time=0
 
def time_for_test(score):
  gap=80-score
  if gap<=0:
    return 0
  else:
    return gap
  
for i in range(n):
  sum_time=sum_time+time_for_test(m[i])
  
print(sum_time)