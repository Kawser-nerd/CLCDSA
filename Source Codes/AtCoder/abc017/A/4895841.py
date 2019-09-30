s = 0
for i in range(3):
    a,b=map(int,input().split())
    s += a*b
print(s//10)