n, m = map(int, input().split())
x, y = map(int, input().split())
a = [int(m) for m in input().split()]
b = [int(m) for m in input().split()]
times = 0
ans = 0
here = "a"
p = 0
q = 0
pf = 0
qf = 0
while pf == 0 and qf == 0:
    if here == "a":
        for i in range(p, n):
            if times <= a[i]:
                times = a[i] + x
                p = i
                here = "b"
                if i == n - 1:
                    pf = 1
                break
            if i == n - 1:
                pf = 1

    else:
        for i in range(q, m):
            if times <= b[i]:
                times = b[i] + y
                q = i
                here = "a"
                ans += 1
                if i == m - 1:
                    qf = 1
                break
            if i == m - 1:
                qf = 1
if here == "a":
    for i in range(p, n):
        if times <= a[i]:
            times = a[i] + x
            p = i
            here = "b"
            if i == n - 1:
                pf = 1
            break
        if i == n - 1:
            pf = 1

else:
    for i in range(q, m):
        if times <= b[i]:
            times = b[i] + y
            q = i
            here = "a"
            ans += 1
            if i == m - 1:
                qf = 1
            break
        if i == m - 1:
            qf = 1
print(ans)