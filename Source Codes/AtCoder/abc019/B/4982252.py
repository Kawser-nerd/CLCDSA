s=input()
a=s[0]
b=0
q=[]
for i in s:
  if a==i:
    b+=1
  else:
    q.append(a)
    q.append(b)
    a=i
    b=1
q.append(a)
q.append(b)
ans=""
for i in q:
  ans+=str(i)
print(ans)