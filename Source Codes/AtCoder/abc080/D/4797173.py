n,c = map(int,input().split())
stc = [list(map(int,input().split())) for i in range(n)]
stc.sort()


R = [[stc[0][1],stc[0][2]]]
for s,t,c in stc[1:]:
    for i in range(len(R)):
        tr,cr = R[i][0],R[i][1]
        if c == cr and tr <=s:
            R[i] = [t,c]
            break
        if c!=cr and tr <s:
            R[i] = [t,c]
            break
    else:
        R.append([t,c])

print(len(R))