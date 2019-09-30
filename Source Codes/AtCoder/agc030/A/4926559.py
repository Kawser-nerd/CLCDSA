A,B,C = input().split()

A = int(A)
B = int(B)
C = int(C)

NpoisunCookie   = A + B 
beautifulCookie = B + C

if C <= A+B:
  print(beautifulCookie)
else:
  print(C-(C-(A+B)) + B + 1)