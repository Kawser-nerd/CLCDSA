a,b,k = map(int,input().split())
c = min(a,b)
count = 0
for i in reversed(range(1,c+1)):
    if a%i==0 and b%i==0:
        count += 1
        if k == count:
            print(i)