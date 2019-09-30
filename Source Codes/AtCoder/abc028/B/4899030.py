s = input()
a=['A','B','C','D','E','F']
b=[]
n=len(s)

for i in range(6):
    s=s.replace(a[i],'')
    b.append(n-len(s))
    n=len(s)
c=map(str,b)
print(' '.join(c))