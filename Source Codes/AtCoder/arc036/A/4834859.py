n,k,*t=map(int,open(0).read().split())
for i in range(n-2):
    if sum(t[i:i+3])<k:
        print(i+3)
        exit()
print(-1)