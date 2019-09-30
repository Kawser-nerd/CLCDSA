s = input()
n= len(s)
a=[]

for i in range(n):
    if s[i]!='B':
        a.append(s[i])
    else:
        if a!=[]:
            del a[-1]
print(''.join(a))