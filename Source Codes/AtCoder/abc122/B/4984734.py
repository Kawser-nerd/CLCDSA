arg=input()
x=len(arg)
count=0
d=[0]

for i in arg:
    if(i=="A" or i=="C" or i=="G" or i=="T"):
        count=count+1
        d.append(count)
    else:
        count=0

print(max(d))