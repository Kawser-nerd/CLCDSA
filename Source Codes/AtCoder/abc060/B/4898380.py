a,b,c = map(int,input().split())
found = False
for i in range(1,b+1):
    if (a * i) % b == c:
        found = True
if found :
    print("YES")
else:
    print("NO")