n = int(input())
a = list(map(int,input().split()))
cnt = 1
temp = 1
for i in range(n-1):
    if a[i]<a[i+1]:
        temp += 1
        cnt += temp
    else:
        cnt += 1
        temp = 1
print(cnt)