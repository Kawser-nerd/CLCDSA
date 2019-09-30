N = int(input())

a = - (- N // 9)

if N % 9 == 0:
    b = '9'
else:
    b = str(N % 9)

print(b * a)