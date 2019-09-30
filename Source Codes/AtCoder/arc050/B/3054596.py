def judge(k):
    global R, B, x, y
    tr, tb, tx, ty = R-k, B-k, x-1, y-1
    return tr//tx + tb//ty >= k


R, B = map(int, input().split())
x, y = map(int, input().split())
l, r = 0, min(R, B)
nxt, prv = 0, -1
while True:
    nxt = (l+r)//2
    if nxt == prv:
        print(nxt+1 if judge(nxt+1) else nxt)
        break
    if judge(nxt):
        l = nxt
    else:
        r = nxt
    prv = nxt