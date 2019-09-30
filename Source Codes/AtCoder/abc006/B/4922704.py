a,b,c=0,0,1
for i in range(int(input()) -1):
  a,b,c=b,c,(a+b+c)%10007
print(a)