s=str(input())
n1=int(s[0])
n2=int(s[1])
n3=int(s[2])
n4=int(s[3])
sum1=0
sum2=0
sum3=0
ans=''
op=['+','-']
for i in range(2):
  if i == 0:
    sum1 = n1+n2
  else:
    sum1 = n1-n2
  for j in range(2):
    if j == 0:
      sum2 = sum1+n3
    else:
      sum2 = sum1-n3
    for k in range(2):
      if k == 0:
        sum3=sum2+n4
      else:
        sum3=sum2-n4
      if sum3==7:
        ans=str(n1)+op[i]+str(n2)+op[j]+str(n3)+op[k]+str(n4)+'=7'
print(ans)