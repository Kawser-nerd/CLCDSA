n = int(input())
a = list(map(int,input().split()))
color =set()
t = 0
for i in range(n):
    if a[i] <=399:
        a[i] = "gray"
    elif a[i]<= 799:
        a[i] = "brown"
    elif a[i]<=1199:
        a[i] = "green"
    elif a[i] <= 1599:
        a[i] = "water"
    elif a[i] <= 1999:
        a[i] ="blue"
    elif a[i] <=2399:
        a[i] ="yellow"
    elif a[i] <=2799:
        a[i] ="daidai"
    elif a[i] <= 3199:
        a[i] = "red"
    else:
        a[i] = "target"
        t += 1
for i in range(n):
    if a[i] != "target":
       color.add(a[i])
    else:
        continue
if len(list(color)) >=1:
    print(len(list(color)),len(list(color))+t)
else:
    print(1,t)