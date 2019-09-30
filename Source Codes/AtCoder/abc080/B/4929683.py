N = int(input())
n = N
tmp = 0

while 1:
    tmp += n%10
    n = int(n/10)
    if n == 0:
        break

print('Yes' if N%tmp == 0 else 'No')