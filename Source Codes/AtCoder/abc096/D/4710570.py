n = int(input())

def is_p(n):
    i = 2
    while i**2 <= n:
        if n % i == 0:
            return False
        i += 1
    return True

l = []
for i in range(2, 55555 + 1):
    if i % 5 == 2 and is_p(i):
        l.append(i)
        if len(l) == n:
            break
            
print(" ".join(map(str, l)))