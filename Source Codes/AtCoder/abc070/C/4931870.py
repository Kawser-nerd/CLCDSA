def gcd(x,y):
    if y==0:
        return x
    return gcd(y,x%y)
n = int(input())
res = 1
for _ in range(n):
    curr = int(input())
    res = (res*curr)//gcd(res,curr)
print(res)