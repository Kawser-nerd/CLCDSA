M = 1000000007
H,W,A,B = map(int,input().split())
factorial_list = [0] * (H+W)
factorial_list[0] = 1
for i in range(1,H+W):
    factorial_list[i] = factorial_list[i-1]*i %M
inverse_factorial_list = [0] * (H+W)

def power(a,n):
    if n == 0:
        return 1
    if n == 1:
        return a % M
    if n % 2 == 0:
        return power(a,n//2)**2 % M
    return (power(a,n-1) * a) % M

inverse_factorial_list[H+W-1] = power(factorial_list[H+W-1],M-2)
for i in range(H+W-2,-1,-1):
    inverse_factorial_list[i] = inverse_factorial_list[i+1] *(i+1) %M

def C(a,b):
    return factorial_list[a+b] * inverse_factorial_list[a] * inverse_factorial_list[b] % M
    
route = 0
for i in range(B,W):
    a = H - A - 1
    b =  i
    c = A - 1
    d = W - i - 1
    route += ((C(a,b)%M) * (C(c,d)%M)) 
    route %= M

print(route)