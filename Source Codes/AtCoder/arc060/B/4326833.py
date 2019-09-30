import math
n = int(input())
s = int(input())

if n == s:
    print(n+1)
    quit()

def f(b, n):
    ret = 0
    while n > 0:
        ret += n % b
        n = n // b
    return ret

for i in range(2, int(math.sqrt(n)+2)):
    t = f(i, n)
    if s == t:
        print(i)
        quit()

ans = 10**18

for x in range(1, int(math.sqrt(n)+10)):
    y = s - x
    b = (n-s)//x+1
    if x < b and y < b and f(b, n) == s:
        ans = min(ans, b)
if ans == 10**18:
    ans = -1
print(ans)