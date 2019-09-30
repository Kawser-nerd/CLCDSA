n=input()
b=input()
c=input()
p=0
for i in range(0,12,2):
    if c[i] in n:
        p+=1
else:
    if p==6:
        p+=1
    if p==5:
        if b in c:
            p+=1
print(8-p if p>2 else 0)