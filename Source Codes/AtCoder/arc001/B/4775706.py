n,m=map(int,input().split())
l=abs(m-n)//10
i=abs(m-n)-l*10
c=0
if 0<=i<=3:
  c=i
elif 4<=i<=7:
  c=1+abs(i-5)
else:
  c=10-i+1
print(l+c)