N = int(input())
T = 0
A = 0
for i in range(N):
    S = input()
    T += S.count('R')
    A += S.count('B')
    
print('TAKAHASHI' if T > A else ('AOKI' if T < A else 'DRAW'))