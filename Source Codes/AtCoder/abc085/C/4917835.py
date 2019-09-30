n, y = map(int, input().split())

for i in range(n+1):
    for j in range(n-i+1):
        if 10000*i + 5000*j + 1000*(n-i-j) == y:
            print(i, j, n-i-j)
            exit()

a = -1
print(a, a, a)