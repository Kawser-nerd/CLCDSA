N=input()
T=int(N)
N=sum(map(int,list(N)))
if T%N==0 :
  print("Yes")
else :
  print("No")