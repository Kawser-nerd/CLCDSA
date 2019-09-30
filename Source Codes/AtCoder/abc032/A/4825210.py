a = int(input())
b = int(input())
n = int(input())

while True:
    if n%a==0 and n%b==0:
        break
    n = n+1

print(n)