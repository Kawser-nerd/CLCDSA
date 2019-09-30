a = int(input())
ar = list(map(int,input().split(" ")))
ar.insert(0,0)
ar.append(0)
count = 0
for i in range(1,a+2):
    count += abs(ar[i]-ar[i-1])
for i in range(1,a+1):
    b = abs(ar[i-1]-ar[i+1])
    c = abs(ar[i-1]-ar[i])
    d = abs(ar[i]-ar[i+1])
    print(count + b - c - d)