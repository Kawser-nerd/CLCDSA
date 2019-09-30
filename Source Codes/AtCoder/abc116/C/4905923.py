def gcd_core(a, b):
    if b == 0:
        return a
    else:
        return gcd_core(b, a % b)


def gcd(arr):
    g = gcd_core(arr[0], arr[1])
    for i in range(2, len(arr)):
        g = gcd_core(g, arr[i])
    return g

n = int(input())
arr = list(map(int,input().split()))
bef = arr[0]
cst = arr[0]
for i in range(1,n):
    if bef < arr[i]:
        cst += arr[i]-bef
    bef = arr[i]

print(cst)