A = int(input())
B = int(input())
C = int(input())
modulo = 10**9+7

AB = (A*B)%modulo
BC = (B*C)%modulo
CA = (C*A)%modulo

y = ((BC-AB)*pow((CA-BC+AB),modulo-2,modulo)) % modulo
x = ((BC-CA)*pow((AB-BC+CA),modulo-2,modulo)) % modulo

print(x,y)