n = int(input())

while n % 2 == 0:
    n //= 2
while n % 5 == 0:
    n //= 5
if n == 1:
    print(1)
else:
    X = [n for i in range(n)]
    
    j = 1
    s = 1
    post = []
    m = 0
    while True:
        s *= 10
        s %= n
        post.append(s)
        X[s] = min(j, X[s])
        m += 1
        if s == 1:
            break
    ans = 0
    while True:
        if ans > 0:
            break
        pre = post
        post = []
        j += 1
        for p in pre:
            pp = (p + 1) % n
            if pp == 0:
                X[0] = j
                ans = j
                break
            if X[pp] == n:
                for i in range(m):
                    post.append(pp)
                    X[pp] = j
                    pp *= 10
                    pp %= n
    print(ans)