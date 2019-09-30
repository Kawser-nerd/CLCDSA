t = int(input())
n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))

a = sorted(a)
b = sorted(b)

ans = "yes"

c = 0
if n >= m :
    for i in range(m):
        for k in range(c,n):
            if b[i] - a[k] <= t and b[i] - a[k] >= 0:
                c += 1
                break 
        if c < i+1:
            ans = "no"
            break
else :
    ans = "no"


print(ans)