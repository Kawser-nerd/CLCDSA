# ??
s=input()
k=int(input())

l=[]

for i in range(len(s)-k+1):
  l.append(s[i:i+k])

# ??
print(len(set(l)))