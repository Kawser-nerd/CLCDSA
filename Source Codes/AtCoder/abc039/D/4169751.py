H, W = map(int,input().split())
S = ["#" + input() + "#" for k in range(H)]
S = ["#"*(W+2)] + S + ["#"*(W+2)]

if H == 1 and W == 1:
    print("possible")
    print(S[1][1])
    exit(0)

A = [["." for l in range(W)] for k in range(H)]

f = 1
for x in range(1,H+1):
    for y in range(1,W+1):
        if S[x][y] == "#":
            if S[x-1][y-1] == S[x-1][y] == S[x-1][y+1] == S[x][y-1] == S[x][y+1] == S[x+1][y-1] == S[x+1][y] == S[x+1][y+1] == "#":
                A[x-1][y-1] = "#"

B = [["." for l in range(W+2)] for k in range(H+2)]
for x in range(1,H+1):
    for y in range(1,W+1):
        if S[x][y] == "#":
            B[x][y] = "#"

for x in range(1,H+1):
    for y in range(1,W+1):
        if B[x][y] == "#":
            if B[x-1][y-1] == B[x-1][y] == B[x][y-1] == "#":
                pass
            elif B[x][y-1] == B[x+1][y-1] == B[x+1][y] == "#":
                pass
            elif B[x-1][y] == B[x-1][y+1] == B[x][y+1] == "#":
                pass
            elif B[x+1][y] == B[x+1][y+1] == B[x][y+1] == "#":
                pass
            else:
                f = 0

if f == 0:
    print("impossible")
else:
    print("possible")
    for r in A:
        print("".join(r))