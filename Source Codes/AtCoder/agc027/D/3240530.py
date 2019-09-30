N = int(input())

if N == 2:
    print(4, 7)
    print(23, 10)
    exit()

a= [[0] * N for _ in range(N)]

def sieve(n):
    '''
    :param n:
    :return: n????????????
    ??????????O(n log log n)
    '''
    prime = []
    is_prime = [True] * (n + 1) #is_prime[i] = True??i???
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, n+1):
        if is_prime[i]:
            prime.append(i)
            for j in range(2 * i, n + 1, i):
                is_prime[j] = False
    return prime

P = sieve(8000) #len(P) > 1000

def p1(k):
    return P[(k // 2) + 1]

def p2(k):
    if k >= 0:
        return P[(k // 2) + N + 1]
    else:
        return P[k // 2]

for i in range(N):
    for j in range(N):
        if (i + j) % 2 == 0:
            a[i][j] = p1(i + j) * p2(i - j)
        else:
            a[i][j] = p1(i + j + 1) * p1(i + j - 1) * p2(i - j + 1) * p2(i - j - 1) + 1

for i in range(N):
    print(' '.join(map(str, a[i])))