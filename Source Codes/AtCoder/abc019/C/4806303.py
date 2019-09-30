input()
a = [int(a) for a in input().split()]
for i in range(len(a)):
    while a[i] % 2 == 0:
        a[i] /= 2
print(len(set(a)))