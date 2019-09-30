a = int(input())
ar = list(map(int,input().split(" ")))
f = 0
k = 0
for r in ar:
    if r % 4 == 0:
        f += 1
    if r % 2 == 1:
        k += 1
if k + f == a:
    if k <= f + 1:
        print("Yes")
    else:
        print("No")
else:
    if k <= f:
        print("Yes")
    else:
        print("No")