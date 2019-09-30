H,W = map(int,input().split())
s = ["."*(W+2)] + ["." + input() + "." for _ in range(H)] + ["."*(W+2)]

out = "Yes"
for i in range(1,H+1):
    for j in range(1,W+1):
        if s[i][j] == "." :
            continue
        for k,l in ((1,0),(-1,0),(0,1),(0,-1)):
            if s[i+k][j+l] == "#":
                break
        else:
            out = "No"
            break
    if out=="No":
        break
print(out)