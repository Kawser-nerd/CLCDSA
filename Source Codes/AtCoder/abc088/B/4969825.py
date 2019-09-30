N=int(input())
a = list(map(int,input().split(" ")))

total=0

for i in range(len(a)):
    if i % 2 == 0 :
        total+=max(a)
        index=a.index(max(a))
        a[index]=0
    else:
        total-=max(a)
        index=a.index(max(a))
        a[index]=0

print(total)