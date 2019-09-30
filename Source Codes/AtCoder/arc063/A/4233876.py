ls=input().strip()
a=ls[0]
b=0
def fun():
     print('a')
     print('b')
for i in ls[1:]:
     if i!=a:
          b+=1
          a=i
print(b)