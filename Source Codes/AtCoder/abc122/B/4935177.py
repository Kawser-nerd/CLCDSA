a=str(input())
b=len(a)
x=0
y=0
for i in range(b):
    if a[i]=="A" or a[i]=="T" or a[i]=="G" or a[i]=="C":
        x +=1
    else:
        x=0
    if (x > y):
        y=x
print(y)