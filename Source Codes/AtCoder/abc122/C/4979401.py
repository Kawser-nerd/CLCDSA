N,Q=map(int,(input()).split())
S=input()
Count=[0]
count=0
for i in range(1,N):
  if S[i-1:i+1]=="AC":
    count+=1
    Count.append(count)
  else:
    Count.append(count)
for i in range(Q):
  l,r=map(int,input().split())
  print(Count[r-1]-Count[l-1])