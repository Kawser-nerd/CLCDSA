n=int(input())
a= list(map(int, input().split()))
isum=0
for i in range(n):
    if(a[i] %2 == 0):
        if a[i] % 6 == 0:
            isum += 3
        else:
            isum +=1
    elif a[i] % 3 == 2:
        isum +=2
print(isum)