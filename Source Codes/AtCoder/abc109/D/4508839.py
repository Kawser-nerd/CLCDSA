h, w = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(h)]

a_odd = [[False if ele%2==0 else True for ele in row] for row in a]

link = [[None]*w for _ in range(h)]
route = [[i,j] if i%2==0 else [i,w-1-j] for i in range(h) for j in range(w)]

linking = False
cnt = 0
tmp = 0
valid_n = -1
for n, [i,j] in enumerate(route):
    if a_odd[i][j] and not(linking):
        linking = True
    elif a_odd[i][j] and linking:
        linking = False
        link[i][j] = prev
        cnt += tmp+1
        tmp = 0
        valid_n = n
    elif not(a_odd[i][j]) and linking:
        link[i][j] = prev
        tmp += 1
    else:
        pass
    prev = [i,j]

print(cnt)
for n,[i,j] in enumerate(route):
    if link[i][j] and n<=valid_n:
        print(link[i][j][0]+1, link[i][j][1]+1, i+1, j+1)
    else:
        pass