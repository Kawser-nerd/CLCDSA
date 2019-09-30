import math

def is_prime(x):
    if x < 2:
        return False
    else:
        t = int(math.sqrt(x)) + 1
        for n in range(2, t):
            if x % n == 0:
               return False
        return True


n = int(input())

cnt = 0
ans = []
for num in range(2, 55555):
    if is_prime(num) and num % 5 == 1:
        cnt += 1
        ans.append(num)

    if cnt == n:
        break

print(*ans)