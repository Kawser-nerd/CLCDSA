N = int(input())
list = [111 * i for i in range(1,10)]
num = 0

for i in list:
    if N <= i:
        num = i
        break

print(num)