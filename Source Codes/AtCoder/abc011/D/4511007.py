#A
"""
n = int(input())
ans = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1]
print(ans[n])
"""
#B
"""
a = input()
print(str.capitalize(a))
"""
#C
"""
n = int(input())
ng = []
for i in range(3):
    a = int(input())
    ng.append(a)
for i in range(100):
    if n in ng:
        print("NO")
        break
    if (n - 3) in ng:
        if (n - 2) in ng:
            if (n - 1) in ng:
                print("NO")
                break
            else:
                n -= 1
        else:
            n -= 2
    else:
        n -= 3
    if n <= 0:
        print("YES")
        break
else:
    print("NO")
"""
#D

def comb(n,k):
    """power_func????(nCk) mod p ????"""
    from math import factorial
    if n<0 or k<0 or n<k: return 0
    if n==0 or k==0: return 1
    a=factorial(n) 
    b = factorial(k)
    c=factorial(n-k)
    return (a / (b * c))
import math

n, d = map(int, input().split())
x, y = map(int, input().split())
x = abs(x)
y = abs(y)
ansn = n
if x % d == 0 and y % d == 0:
    ax = x // d
    ay = y // d
    ansb= 0
    nb = n - ax - ay
    if nb % 2 == 0:
        nb = nb // 2
        for i in range(nb + 1):
            ans = math.exp(math.log(comb(n, i + ax))+math.log(comb(n - i - ax, i))+math.log(comb(n - 2 * i - ax, ay + nb - i))-n*math.log(4))
            ansb += ans
        print(ansb)
    else:
        print(0)
else:
    print(0)