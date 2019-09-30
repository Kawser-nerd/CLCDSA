A,B,C = map(int,input().split())
d = 10**9 + 7
A %= d
B %= d
C %= d
print(A*B*C%d)