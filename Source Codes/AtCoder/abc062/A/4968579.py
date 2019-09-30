a = [1,3,1,2,1,2,1,1,2,1,2,1]

x,y = map(int, input().split())
if a[x-1] == a[y-1]:
    print("Yes")
else:
    print("No")