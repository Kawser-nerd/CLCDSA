N,H = map(int,input().split())
A,B,C,D,E = map(int,input().split())
import math

for X in range(N+1):

    if X == 0:

        if ((N-X)*E-H-B*X) >= 0:

            a = A*X+C*((((N-X)*E-H-B*X) // (D+E))+1)

        else:

            a = 0

    else:

        if ((N-X)*E-H-B*X) >= 0:

            a = min([a,A*X+C*((((N-X)*E-H-B*X) // (D+E))+1)])

        else:

            a = min([a,A*X])

print(a)