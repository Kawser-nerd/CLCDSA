na,nb = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = a + b
t = len(set(c))
s = len(c) - t
print(s / t)