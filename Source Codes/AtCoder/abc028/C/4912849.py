a,b,c,d,e=map(int,input().split())
s=a+b+c+d+e
l=[a,b,c,d,e]
l1=[]
for i in range(4):
  for j in range(i+1,5):
    l1.append(s-l[i]-l[j])
l1=sorted(l1)
print(l1[-3])