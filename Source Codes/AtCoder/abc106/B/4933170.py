N = int(input())

def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    return divisors

ans = 0

if N%2 == 0:
    for j in range(int(N/2)):
        temp = len(make_divisors(2*j+1))
        if temp == 8:
            ans += 1
else:
    for j in range(int(N/2)+1):
        temp = len(make_divisors(2*j+1))
        if temp == 8:
            ans += 1
    
print(ans)