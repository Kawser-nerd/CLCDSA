s=input()
X=[]
for i in range(0,len(s)-2):
  x=abs(753-int(s[i]+s[i+1]+s[i+2]))
  X.append(x)
print(min(X))