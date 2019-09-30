s=input()
w=b=False
cnt=0
for i in s:
  if i=="B":
    if w==True:
      cnt+=1
      w=False
      b=True
    else:
      b=True
  else:
    if b==True:
      cnt+=1
      b=False
      w=True
    else:
      w=True
print(cnt)