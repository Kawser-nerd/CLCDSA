N=int(input())
a=[int(input()) for _ in range(N)]
count=0
nexti=1
for i in range(N):
    nexti=a[nexti-1]
    count+=1
    if(nexti==2):
        print(count)
        exit()
print(-1)