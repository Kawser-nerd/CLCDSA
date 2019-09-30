n = int(input())
a = [int(i) for i in input().split()]

ans = 0
while True:
    c = 0
    exist = False
    for i in range(n):
        if a[i] > n-1:
            c = a[i] // n
            a[i] %= n
            for j in range(n):
                if j != i:
                    a[j] += c
            ans += c
            exist = True
    if not exist:
        break

print(ans)