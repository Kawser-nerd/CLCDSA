n = int(input())
c = []

for i in range(n):
    c.append(int(input()))

e = 0

for i in range(n):
    divisor = 0
    
    for j in range(n):
        if i != j and c[i] % c[j] == 0:
            divisor += 1
    
    if divisor % 2 == 0:
        e += (divisor // 2 + 1) / (divisor + 1)
    else:
        e += 1 / 2

print(e)