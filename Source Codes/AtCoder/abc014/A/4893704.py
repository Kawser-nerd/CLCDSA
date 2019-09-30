a=int(input())
b=int(input())
print(0 if a%b==0 else ((a//b)+1)*b-a)