n=int(input())
s=input()
x=0
list=[]
for i in range(n):
  if s[i]=='I':
    x+=1
  else:
    x-=1
  list.append(x)
print(sorted(list)[-1] if sorted(list)[-1]>=0 else 0)