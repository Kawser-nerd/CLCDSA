n=int(input())
s=str(input())
s1=''
s2=''
max=0
for i in range(1,n-1):
  count={}
  s1=s[:i]
  s2=s[i:]
  for j in range(len(s1)):
    if s2.count(s1[j]) >= 1:
      count[s1[j]]=1
  data=list(count.keys())
  if len(data) > max:
    max=len(data)
print(max)