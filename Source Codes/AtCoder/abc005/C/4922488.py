t = int(input())
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

p = 0
e = 0
for x in b:
    #print(x, p)
    for i in range(p, n):
        if a[i] <= x <= a[i] + t:
            e += 1
            p = i + 1
            break
    else:
        break

if e == m:
    print('yes')
else:
    print('no')