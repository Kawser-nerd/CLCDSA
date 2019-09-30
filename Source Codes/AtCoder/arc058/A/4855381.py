N, K = [int(_) for _ in input().split()]
D = [int(_) for _ in input().split()]

def check(x, D):
    while x > 0:
        x, k = divmod(x, 10)
        if k in D:
            return False
    return True

result = N

while 1:
    if check(result, D):
        break
    result += 1

print(result)