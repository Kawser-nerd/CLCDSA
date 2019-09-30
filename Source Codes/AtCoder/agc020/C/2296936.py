# seishin.py
N = int(input())
*A, = map(int, input().split())
S = sum(A)

b = 1
for a in A:
    b |= b << a
b >>= (S + 1) // 2
print((b & -b).bit_length() - 1 + (S + 1) // 2)