a,b,c = map(int,input().split(" "))
ar = list(map(int,input().split(" ")))
count = 0
for i in range(a-1):
    if (ar[i+1] - ar[i]) * b <= c:
        count += (ar[i+1] - ar[i]) * b
    else:
        count += c
print(count)