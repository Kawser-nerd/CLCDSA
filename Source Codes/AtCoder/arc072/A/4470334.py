n=int(input())
a=list(map(int,input().split()))
count1=a[0]
count2=a[0]
answer1=0
answer2=0

if a[0]<=0:
  answer1+=(1-a[0])
  count1=1
if a[0]>=0:
  answer2+=(1+a[0])
  count2=-1
    
for i in a[1:]:
  if (count1>0 and count1+i<0) or (count1<0 and count1+i>0):
    count1+=i
    continue
  else:
    answer1+=abs(count1+i)+1
    if count1>0:
      count1=-1
    else:
      count1=1
for i in a[1:]:
  if (count2>0 and count2+i<0) or (count2<0 and count2+i>0):
    count2+=i
    continue
  else:
    answer2+=abs(count2+i)+1
    if count2>0:
      count2=-1
    else:
      count2=1  
print(min(answer1,answer2))