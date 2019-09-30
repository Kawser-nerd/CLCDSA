n,k=[int(i) for i in input().split()]
res=False
time=[int(input()),int(input()),int(input())]
for i in range(n-3):
    if sum(time)<k and not res:
        res=i+3
    time[0],time[1],time[2]=time[1],time[2],int(input())
print(res if res else -1)