from collections import deque

H,W = map(int,input().split())
s = [['#'] * (W+2) for i in range(H+2)]
black = 0
for h in range(H):
    S = input()
    for w in range(W):
        s[h+1][w+1] = S[w]
        if S[w] == '#':
            black += 1

dxy = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def bfs(gh,gw):
    st = deque()
    sts = deque()
    push,pop = st.append, st.pop
    pushs,pops = sts.append, sts.pop
    cnt = 1
    push([-1,-1])
    pushs([-1,-1])
    push([1,1])
    g = 0
    while g < 1:
        t = 0
        for i in range(999999):
            now = pop()
            if now == [-1,-1]:
                push([-1,-1])
                break
            pushs(now)
        cnt += 1
        c = 0
        while t < 1:
            now = pops()
            #print(now,c)
            if now == [-1,-1]:
                if c == 0:
                    return -1
                    break
                pushs([-1,-1])
                t = 1
                break
            c = 1

            
            for dx,dy in dxy:
                if s[now[0]+dx][now[1]+dy] == '#':
                    continue
                if [now[0]+dx,now[1]+dy] == [gh,gw]:
                    g = 1
                    #print(cnt,black)
                    return H*W-black-cnt
                if s[now[0]+dx][now[1]+dy] == '.':
                    push([now[0]+dx,now[1]+dy])
                    s[now[0]+dx][now[1]+dy] = '#'

print(bfs(H,W))