H, W = map(int, input().split())
S = [input() for i in range(H)]

def check(l):
    u = [0]*W
    mid = W % 2
    for i in range(W):
        if u[i]:
            continue
        for j in range(i+1, W):
            for p, q in l:
                sp = S[p]; sq = S[q]
                if sp[i] != sq[j] or sp[j] != sq[i]:
                    break
            else:
                u[j] = 1
                break
        else:
            if mid:
                for p, q in l:
                    sp = S[p]; sq = S[q]
                    if sp[i] != sq[i]:
                        break
                else:
                    mid = 0
                    continue
            break
    else:
        return 1
    return 0

def make(c, l, u, p):
    while c in u:
        c += 1
    if c == H:
        if check(l):
            print("YES")
            exit(0)
        return
    if p:
        l.append((c, c))
        make(c+1, l, u, 0)
        l.pop()
    for i in range(c+1, H):
        if i in u:
            continue
        u.add(i)
        l.append((c, i))
        make(c+1, l, u, p)
        l.pop()
        u.remove(i)

make(0, [], set(), H%2)
print("NO")