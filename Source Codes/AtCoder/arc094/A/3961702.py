ar = list(map(int,input().split(" ")))
ar.sort()
count = 0
count += (ar[2] - ar[0]) // 2
count += (ar[2] - ar[1]) // 2
if (ar[2] - ar[0]) % 2 == 0 and (ar[2] - ar[1]) % 2 == 0:
    print(count)
elif (ar[2] - ar[0]) % 2 == 0 or (ar[2] - ar[1]) % 2 == 0:
    print(count + 2)
else:
    print(count + 1)