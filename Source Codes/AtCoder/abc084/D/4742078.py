from itertools import accumulate


# ?????????
# is_prime := 1~n??????
# table := 2~n?????
def sieve(n):
    is_prime = [True for _ in range(n)]
    is_prime[0] = False

    for i in range(2, n+1):
        if is_prime[i-1]:
            j = 2 * i
            while j <= n:
                is_prime[j-1] = False
                j += i
    table = [i for i in range(1, n+1) if is_prime[i-1]]
    return is_prime, table


Q = int(input())
L = [0]*Q
R = [0]*Q

for i in range(Q):
    L[i], R[i] = list(map(int, input().split()))

max_R = max(R)
is_prime, table = sieve(max_R)

check = [0]*(max_R + 1)
for i in range(0, max_R + 1):
    if (i % 2 == 1):
        if (is_prime[i-1] and is_prime[(i+1)//2-1]):
            check[i] = 1

# ???
check = [0] + check
check = list(accumulate(check))

for i in range(Q):
    print(check[R[i] + 1] - check[L[i]])