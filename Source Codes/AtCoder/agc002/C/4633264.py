n, l = map(int, input().split())
a = list(map(int, input().split()))
b = [a[i]+a[i+1] for i in range(n-1)]
start = -1
for ind, length in enumerate(b):
    if length >= l:
        start = ind+1
        break
if start<0:
    print("Impossible")
else:
    print("Possible")
    for i in range(1,start):
        print(i)
    for i in range(start, n)[::-1]:
        print(i)