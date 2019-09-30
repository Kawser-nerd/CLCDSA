n = int(input())
lis = list(map(int,input().split()))
if sum(lis) % sum([i for i in range(1,n+1)]) != 0:
    print("NO")
    exit()
key = sum(lis) // sum([i for i in range(1,n+1)])
li = [-lis[i]+lis[i-1]+key for i in range(n)]
for num in li:
    if num < 0 or num % n != 0:
        print("NO")
        exit()
print("YES")