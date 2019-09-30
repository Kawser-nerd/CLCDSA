from sys import stdin

n = int(stdin.readline().rstrip())

def tribonacci(n):
    if n == 1:
        return 0
    elif n == 2:
        return 0
    elif n == 3:
        return 1
    else:
        newN = n - 3
        num1, num2, num3 = 0, 0, 1
        for i in range(newN):
            num1, num2, num3 = num2 % 10007, num3 % 10007, (num1 + num2 + num3) % 10007
        return num3

print(tribonacci(n))