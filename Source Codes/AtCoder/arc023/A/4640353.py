y = int(input())
m = int(input())
d = int(input())
def f(x):
    return int(x // 1)
def F(y,m,d):
    if m == 1 or m == 2:
        y -= 1
        m += 12
    return int(365*y + f(y/4) - f(y/100) + f(y/400) + f(306*(m+1)/10) + d - 429)
print(F(2014,5,17)-F(y,m,d))