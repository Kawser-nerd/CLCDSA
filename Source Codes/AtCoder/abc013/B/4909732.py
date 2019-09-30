a = int(input())
b = int(input())
print(min(abs(a-b),abs(0-a)+abs(9-b)+1,abs(0-b)+(9-a)+1))