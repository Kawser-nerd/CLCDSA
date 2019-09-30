n,m,a,b = map(int,input().split())
for i in range(m):
    if n <= a:
        n += b

    c = int(input())
    n -= c 
    if n < 0:
        print(i+1)
        exit()
print("complete")