N = int(input())

result = []
memo = N
while memo > 0:
    result.append(memo % 10)
    memo //= 10

if N % sum(result) == 0:
    print("Yes")
else:
    print("No")