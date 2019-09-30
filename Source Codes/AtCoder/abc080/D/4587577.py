N, C = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(N)]
L.sort(key=lambda x: x[0])
R = [(L[0][1], L[0][2])]
for s, t, c in L[1:]:
    for i, (t_r, c_r) in enumerate(R):
        if c == c_r and t_r <= s:
            R[i] = (t, c)
            break
        if c != c_r and t_r < s:
            R[i] = (t, c)
            break
    else:
        R.append((t, c))
print(len(R))