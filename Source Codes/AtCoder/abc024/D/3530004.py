A = int(input())
B = int(input())
C = int(input())

m = 10**9+7
inv = pow((B+C)*A-B*C,m-2,m)
r = (B-A)*C*inv%m
c = (C-A)*B*inv%m

print('{} {}'.format(r,c))