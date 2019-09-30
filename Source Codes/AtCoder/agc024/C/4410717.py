n = int(input())
a = []
for i in range(n):
    temp = int(input())
    a.append(temp)
if a[0] != 0:
    print("-1")
else:
    check = True
    for i in range(n-1):
        if a[i+1] >= a[i] + 2:
            print("-1")
            check = False
            break
    if check:
        ans = sum(a)
        for i in range(n-1):
            if a[i+1] == a[i]+1:
                ans -= a[i]
        print(ans)