def get(x):
    cnt = 0
    while x % 2 == 0:
        cnt += 1
        x = x/2
    return cnt
n = int(input())
at = 1
ans = 0
for i in range(1,n+1):
    a = get(i)
    if ans < a:
        ans = a
        at = i
print(at)