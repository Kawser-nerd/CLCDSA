d,s,t=map(int,input().split())
w=int(input())
count=0
if s<=w<=t:
  count+=1
for _ in range(d-1):
  a=int(input())
  w+=a
  if s<=w<=t:
    count+=1
print(count)