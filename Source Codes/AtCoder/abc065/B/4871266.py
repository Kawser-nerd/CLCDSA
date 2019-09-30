n = int(input())
a = [int(input()) for _ in range(n)]
cnt = 0
k = 0
while cnt<n:
    if a[k]==2:
        print(cnt+1)
        exit()
    else:
        k = a[k]-1
        cnt+=1
print(-1)