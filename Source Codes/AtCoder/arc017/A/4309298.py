N = int(input())

def prime_number(n):
    for i in range(2, n+1):
        if i * i > n:
            return True
        if n%i == 0:
            return False
    return n != 1
       
if prime_number(N):
    print("YES")
else:
    print("NO")