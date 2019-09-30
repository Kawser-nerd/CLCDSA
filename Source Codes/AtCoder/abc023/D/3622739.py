N=int(input())
Balloons=[[int(i) for i in input().split()] for i in range(N)]

def find(x):
  Time=[]
  for b in Balloons:
    h,s=b[0],b[1]
    if x-h<0:
      return False
      break
    Time.append((x-h)/s)
  Time.sort(key=lambda x:x)
  for n in range(N):
    if Time[n]<n:
      return False
      break
    if n==N-1:
      return True

left,right=0,10**15

while left<right:
  if find((left+right)//2):
    right=(left+right)//2
  else:
    left=(left+right)//2+1
print(left)