list=input().split(" ")
a=input().split(" ")

b=int(list[1])

sum=0
for i in range(int(list[0])):
    if b%2==1:
        sum+=int(a[i])
    b=b//2

print(sum)