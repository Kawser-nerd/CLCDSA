N, X = map(int, input().split())

x = [int(i) for i in input().split()]

x.append(X)
x.sort()

def gcd(x, y):
    if x < y:
        x, y = y, x
    if y == 0:
        return x
    else:
        return gcd(y, x%y)

now = x[1] - x[0]

for i in range(1, N):
    distance = x[i+1] - x[i]
    now = gcd(now, distance)
    if now == 1:
        break
print(now)