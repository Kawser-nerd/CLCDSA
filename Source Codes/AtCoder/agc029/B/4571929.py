import bisect
def reversed_num(num):
  num_len=len(bin(num))-2
  f=2**num_len-1
  return num^f
n=int(input())
number=list(map(int,input().split()))
number.sort()
count=0
while len(number)>0:
  k=number.pop()
  if len(number)==0:
    break
  if k==int(k):
    x=reversed_num(k)+1
    y=bisect.bisect_left(number,x)
    if x>number[-1]:
      y-=1
    if number[y] ==x:
      number[y]-=0.5
      count+=1
print(count)