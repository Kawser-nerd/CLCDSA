t = int(input())
n = int(input())
ts = list(map(int,input().split()))
m = int(input())
cs = list(map(int,input().split()))

ans = "no"

if n >= m:
    count = 0
    for i in ts:
        customer = cs[count]
        if i <= customer and customer <= i+t:
            count += 1
        if count == m:
            ans = "yes"
            break
print(ans)