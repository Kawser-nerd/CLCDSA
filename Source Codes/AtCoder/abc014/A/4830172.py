a = int(input())
b = int(input())
if a%b==0:
    print(0)
    exit()
else:
    c = a//b+1
    print(c*b-a)