n=int(input())
li=[]
for i in range(1,n):
  li.append(sum(list(map(int,list(str(i)))))+sum(list(map(int,list(str(n-i))))))
print(min(li))