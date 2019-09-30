n=int(input())
s=input()
min=9999
max=0
for i in range(1,5):
    x=s.count(str(i))
    if min>x:
        min=x
    if max<x:
        max=x
print(max,min)