h, w = map(int, input().split())
s = [input() for i in range(h)]

for i in range(h):
    for j in range(w):
        if s[i][j] == '.':
            count = 0
            for i_ in range(i-1, i+2):
                for j_ in range(j-1, j+2):
                    if 0<= i_ <h and 0<= j_ <w:
                        if s[i_][j_] == '#':
                            count += 1
            s[i]=s[i][:j]+str(count)+s[i][j+1:]

for i in range(h):
    print(s[i])