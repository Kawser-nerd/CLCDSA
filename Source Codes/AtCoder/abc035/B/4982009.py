# ??
S=input()
T=int(input())

# '?'??????????
c=0

# x????y??????????????
x=y=0

for a in S:
  if a=='R':
    x+=1
  elif a=='L':
    x-=1
  elif a=='U':
    y+=1
  elif a=='D':
    y-=1
  # '?'???
  else:
    c+=1

# ???????????
d=abs(x)+abs(y)

# ??????????
if T==1:
  print(d+c)
# ??????????
else:
  # '?'??????????????????
  if d<c:
    # ??????????0????
    if (c-d)%2==0:
      print(0)
    # ???????????????1??
    else:
      print(1)
  else:
    print(d-c)