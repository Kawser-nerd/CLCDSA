num = 1
n = int(input())
k = int(input())

while num <= k and n:
    num *= 2
    n -= 1
while n:
    num += k
    n -= 1
print(num)