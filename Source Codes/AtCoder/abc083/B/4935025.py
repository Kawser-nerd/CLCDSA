import sys
n, a, b = [int(i) for i in sys.stdin.readline().split()]
total = 0
for i in range(1, n + 1):
    digit_sum = sum([int(i) for i in list(str(i))])
    if a <= digit_sum and digit_sum <= b:
        total += i
print(total)