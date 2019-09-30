n=int(input())
name=[]
for i in range(n):
    name.append(input())

max=0
for i in range(n):
    if max<name.count(name[i]):
        max_name=name[i]
        max=name.count(name[i])
print(max_name)