a = int(input())
b = int(input())
n = int(input())

for i in range(n, 100000):
    if i%a==0 and i%b==0:
        print(i)
        break