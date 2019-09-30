l=list(input())
ca=0
cb=0
cc=0
cd=0
ce=0
cf=0
for i in l:
  if i=="A":
    ca+=1
  elif i=="B":
    cb+=1
  elif i=="C":
    cc+=1
  elif i=="D":
    cd+=1
  elif i=="E":
    ce+=1
  else:
    cf+=1
print(ca,cb,cc,cd,ce,cf)