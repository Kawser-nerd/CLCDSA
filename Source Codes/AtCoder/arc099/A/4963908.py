import math
x=input().split(" ")
length=int(x[0])
k=int(x[1])

a=length-1
b=k-1

print(math.ceil(a/b))