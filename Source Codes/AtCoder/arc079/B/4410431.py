def counter(a,n):
    big = max(a)
    check = True
    counter = 0
    while big > n-1:
        for i in range(n):
            if a[i] == big and check:
                check = False
                a[i] -= n
            else:
                a[i] += 1
        counter += 1
        big = max(a)
        check = True
    return counter

k = int(input())
n = 50
print(n)
temp = k//50
a = [49+temp for i in range(n)]
k = k - 50*(k//50)
for i in range(k):
    big = min(a)
    check = True
    for j in range(n):
        if a[j] == big and check:
            check = False
            a[j] += 50
        else:
            a[j] -= 1
for i in range(n):
    if i != n-1:
        print(a[i],end = " ")
    else:
        print(a[i])