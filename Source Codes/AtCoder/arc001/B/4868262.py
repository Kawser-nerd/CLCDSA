n=int(input())
l=list(input())
l2=[]
for i in range(1,5):
  l2.append(l.count(str(i)))
print(max(l2),min(l2))