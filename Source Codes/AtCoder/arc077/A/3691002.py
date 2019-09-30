def inpl(): return [int(i) for i in input().split()]
n = int(input())
a = inpl()
ans = [0 for _ in range(n)]
if n%2:
    for i,ai in enumerate(a):
        if i%2:
            ans[n//2+(i+1)//2] = ai
        else:
            ans[n//2-(i+1)//2] = ai
else:
    for i,ai in enumerate(a):
        if i%2:
            ans[n//2-(i+1)//2] = ai
        else:
            ans[n//2+(i+1)//2] = ai
print(*ans)