def inpl(): return [int(i) for i in input().split()]
N = int(input())
a = inpl()
b = {a[i]: i for i in range(N)}

left = list(range(N+2))
right = list(range(N+2))

ans = 0
for i in range(N,0,-1):
    x = b[i]
    ans += i*(right[x]-x +1)*(x-left[x] +1)
    right[left[x] - 1] = right[x]
    left[right[x] + 1] = left[x]
print(ans)