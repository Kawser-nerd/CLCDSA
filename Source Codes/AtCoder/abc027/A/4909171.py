a = list(map(int, input().split()))
if a[0] == a[1]:
    print(a[2])
elif a[1] == a[2]:
    print(a[0])
else:
    print(a[1])