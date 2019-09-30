N = int(input())
b = [int(i) for i in input().split()]
a = [0 for i in range(N)]
number = []
for j in range(N):
    for i in range(len(b)-1,-1,-1):
        if(i+1==b[i] and a[i]==0):
            del a[i]
            number.append(b[i])
            del b[i]
            break
if(not a):
    for i in range(N):
        print(number.pop())
if(a):
    print(-1)