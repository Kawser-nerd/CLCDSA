n = int(input())
prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
ps = {}
def primes(x, k):
    cnt = 0
    for i in range(1,x+1):
        while i % k == 0:
            cnt += 1
            i = i / k
    return cnt
for i in prime:
    ps[i] = primes(n, i)
sevfo = 0
twefo = 0
fot = 0
four = 0
two = 0
for value in ps.values():
    if value >= 74:
        sevfo += 1
        twefo +=1
        fot += 1
        four += 1
        two += 1
    elif value >= 24:
        twefo += 1
        fot += 1
        four += 1
        two += 1
    elif value >= 14:
        fot += 1
        four += 1
        two += 1
    elif value >= 4:
        four += 1
        two += 1
    elif value >= 2:
        two += 1
if (four >= 2 and two >= 3) or sevfo >= 1 or (twefo >= 1 and two >= 2) or (fot >= 1 and four >= 2):
    a = int(((four-1)*four / 2)*(two-2))
    b = fot * (four -1)
    c = twefo * (two-1)
    d = sevfo
    print(a+b+c+d)
else:
    print(0)