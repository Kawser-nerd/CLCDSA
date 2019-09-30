N=int(input())
Price=[]
for i in range(N):
  p=int(input())
  Price.append(p)
Price.sort()
print(sum(Price)-int(Price[-1]/2))