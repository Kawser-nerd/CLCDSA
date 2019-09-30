A, B, C = map(int, input().split())
M = 1000000007

A %= M
B %= M
C %= M

print((A*B*C)%M)