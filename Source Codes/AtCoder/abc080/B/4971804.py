N = int(input())
Nsum = 0
n = N
while n > 0:
    y = n % 10
    Nsum += y
    n = n // 10
if N % Nsum == 0:
    print('Yes')
else:
    print('No')