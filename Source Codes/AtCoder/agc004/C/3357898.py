H,W=map(int,input().split())
a=[list(input()) for i in range(H)]
b=[["." for i in range(W)] for i in range(H)]
c=[["." for i in range(W)] for i in range(H)]
for i in range(H):
    c[i][0]="#"
    b[i][-1]="#"
for i in range(H):
    for j in range(W):
        if i%2==0:
            b[i][j]="#"
        else:
            c[i][j]="#"
for i in range(H):
    c[i][-1]="."
    b[i][0]="."
for i in range(H):
    for j in range(W):
        if a[i][j]=="#":
            b[i][j]="#"
            c[i][j]="#"

for i in b:
    print("".join(i))
print()
for i in c:
    print("".join(i))