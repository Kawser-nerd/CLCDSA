from fractions import Fraction
import fractions
 
X, Y = map(int, input().split("/"))
N = 2 * X // Y
f = False
                
for N in range(N - 5, N + 5):
    if N <= 0:
        continue
    if X * N % Y != 0:
        continue            
    M = Fraction(N * (N + 1) - Fraction(2 * X * N, Y), 2)
    if M.denominator == 1 and 1 <= M <= N:
        print(N, int(M))
        f = True
 
if f == False:
    print("Impossible")