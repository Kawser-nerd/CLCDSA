a = []
import bisect
for i in range(1,10**5+1):
    if i ** 2 > 10**9:
        break
    a.append(i**2)

n = int(input())
x = bisect.bisect_right(a,n)
print(a[x-1])