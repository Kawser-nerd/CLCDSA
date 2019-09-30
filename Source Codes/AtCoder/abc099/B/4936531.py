a,b = map(int,input().split())

div = b-a
num = 0
for i in range(1,div):
  num += i
print(num-a)