Y = int(input())
M = int(input())
D = int(input())

def f(y, m, d):
    return 365 * y + y // 4 - y // 100 + y // 400 + (306 * (m + 1)) // 10 + d - 429

if M == 1:
    Y -= 1
    M = 13
elif M == 2:
    Y -= 1
    M = 14
    
print(f(2014, 5, 17) - f(Y, M, D))