n = int(input())
b = list(map(int,input().split()))

ans = []

while len(b) > 0:
    check = -1
    for i in range(len(b)):
        if b[i] == i+1:
            check=i
    if check==-1:
        print(-1)
        exit()
    ans.append(check+1)
    b = b[:check] + b[check+1:]
for i in range(n):
    print(ans[n-i-1])