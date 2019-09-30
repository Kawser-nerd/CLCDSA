n = int(input())
a = list(map(int,input().split()))
b = [[a[i],i+1] for i in range(n)]
b.sort()
for c in b[::-1]:
    print(c[1])