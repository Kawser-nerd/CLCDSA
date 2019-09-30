n = int(input())
b = [int(input()) for _ in range(n)]
l = [0]*(n+1)
for i in range(n):
    l[i+1] = l[i]^b[i]
if l[-1] != 0:
    print(-1)
else:
    l.pop()
    for i in l:
        print(i)