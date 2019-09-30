k = int(input())
def ispf(n,m):
    return (((9 * n) - 1)*pow(10, n) + 1) + pow(10, n) * (sum([int(l) for l in str(m)]) - 10*m)
result = []
for n in range(100):
    for i in range(100000):
        if ispf(n,i)<0:
            break
        for j in range(10):
            result.append(int(str(i) + str(j) + '9'*n))
for item in sorted(list(set(result[1:])))[:k]:
    print(item)