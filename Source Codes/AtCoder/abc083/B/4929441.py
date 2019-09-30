N, A, B = map(int, input().split())
sums = 0

for i in range(1, N+1):
    tmp = 0
    num = i

    while 1:
        tmp += num%10
        num = int(num/10)
        if num == 0:
            break

    if A <= tmp <= B:
        sums += i


print(sums)