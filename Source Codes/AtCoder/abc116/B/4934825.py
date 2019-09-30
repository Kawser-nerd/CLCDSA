s=int(input())
tmp=[]
while s not in tmp:
    tmp.append(s)
    if s%2==0:
        s//=2
    else:
        s=3*s+1
print(len(tmp)+1)