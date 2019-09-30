n, m = map(int,input().split())
s = []
for i in range(n):
    s.append(input())
t = []
for i in range(m):
    t.append(input())
found = False
for i in range(0,n-m+1):
    for j in range(0,n-m+1):
        f = True
        for k in range(m):
            for l in range(m):
                if t[k][l] != s[i+k][j+l]:
                    f = False
                    break
        if f == True:
            found = True

if found :
    print("Yes")
else:
    print("No")