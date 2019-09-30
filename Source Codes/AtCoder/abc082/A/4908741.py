a, b= map(int, input().split())
s= a + b
x= s / 2
if s %2 == 0:
    print(int(x))
else:
    print(int(x)+1)