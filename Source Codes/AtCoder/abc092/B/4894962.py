n = int(input())
d , x = map(int,input().split())
cnt = 0
for i in range(n):
    a = int(input())
    st = 1
    while st <= d:
        st += a
        cnt += 1
print(cnt+x)