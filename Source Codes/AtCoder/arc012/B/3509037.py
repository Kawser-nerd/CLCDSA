list=input().split(" ")
a=int(list[1])
b=int(list[2])
c=int(list[3])

for i in range(int(list[0])):
    full=c/a
    full2=full*b

    c=full2

print(c)