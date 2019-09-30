N, C = map(int, input().split())
STC = [[int(i) for i in input().split()] for i in range(N)]
STC.sort()

R = [[STC[0][1], STC[0][2]]]
for s, t, c in STC[1:]:
    for i in range(len(R)):
        t_r, c_r = R[i][0], R[i][1]
        if c == c_r and t_r <= s:
            R[i] = [t, c]
            break
        if c != c_r and t_r < s:
            R[i] = [t, c]
            break
    else:
        R.append([t, c])
        
print(len(R))