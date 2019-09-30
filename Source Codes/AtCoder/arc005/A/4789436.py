n = int(input())
lis = input().split()
words = ["TAKAHASHIKUN","Takahashikun","takahashikun"]
cnt = 0
for i in range(n):
    w = lis[i]
    if i == n-1:
        w = w[:-1]
    if w in words:
        cnt+= 1

print(cnt)