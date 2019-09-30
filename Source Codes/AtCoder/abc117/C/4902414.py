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


n,m = map(int,input().split())
arr = list(map(int,input().split()))
arr.sort()
temp = []
for i in range(m-1):
    temp.append(arr[i+1]-arr[i])
temp.sort()
temp[::-1]
ans = 0

for i in range(m-n):
    ans += temp[i]
print(ans)