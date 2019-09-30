N=int(input())
Red=[]
Blue=[]
for _ in range(N):
  Red.append(list(map(int,input().split())))
for _ in range(N):
  Blue.append(list(map(int,input().split())))

Red.sort(key=lambda x:x[1])
Blue.sort(key=lambda x:(x[0],x[1]))

answer=0
for Bluei in range(N):
  popwant=101
  count=0
  while(True):
    if count==len(Red) or Blue[Bluei][1]<=Red[count][1]:
      break
    if Red[count][0]<Blue[Bluei][0]:
      popwant=count
    count+=1
  if popwant<100:
    Red.pop(popwant)
    answer+=1
print(answer)