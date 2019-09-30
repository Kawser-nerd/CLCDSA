N=int(input()) #??N???
Ans=N #?????????
suu=input()
ListNum=list(map(int,suu.split()))
c=0
for i in range(0,len(ListNum),1):
  try:
    if ListNum[i]<ListNum[i+1]: 
      c+=1
    else:
      b=c*(C+1)/2
      Ans+=b
      c=0
      continue
  except:
    b=c*(c+1)/2
    Ans+=b
    c=0
    if i==len(ListNum)-1:
      break
print(int(Ans))