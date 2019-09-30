A=int(input())
B=int(input())
C=int(input())
P=10**9+7
X=(A*C-B*C+A*B)%P
Y=(B*C-A*B)%P
Z=(B*C-A*C)%P
def egcd(a, b):
    (x, lastx) = (0, 1)
    (y, lasty) = (1, 0)
    while b != 0:
        q = a // b
        (a, b) = (b, a % b)
        (x, lastx) = (lastx - q * x, x)
        (y, lasty) = (lasty - q * y, y)
    return (lastx, lasty, a)
def inv(x):
    return egcd(x,P)[0]
r=(Z*inv(X))%P
c=(Y*inv(X))%P
print(r,c)