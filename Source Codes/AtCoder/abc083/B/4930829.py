def rank(num):
  if num==10000:
    return 1
  else:
    return(num%10+int(num%100/10)+int(num%1000/100)+int(num%10000/1000))
 
n,a,b = map(int,input().split())
count = 0
 
for i in range(1,n+1):
  if a <= rank(i) <= b:
    count +=i
 
print(count)