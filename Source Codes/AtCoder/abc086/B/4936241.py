a, b = input().split()
c = int(a+b)

# print(c)

def try_square_root_naive(n):
    m = int(n**.5)
    return m if abs(m*m - n) < 1e-6 else None

if try_square_root_naive(c)==None:
    print('No')
else:
    print('Yes')