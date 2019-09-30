a = int(input())
b = int(input())
c = int(input())

l = sorted([a,b,c],reverse=True)
print(l.index(a)+1)
print(l.index(b)+1)
print(l.index(c)+1)