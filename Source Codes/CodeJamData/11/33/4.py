T = int(raw_input())

for t in range(T):
    N,L,H = map(int, raw_input().split(' '))
    notes = map(int, raw_input().split(' '))

    ffound = False
    for l in range(L,H+1):
        if len(filter(lambda x: x == l or max(x,l)%min(x,l) == 0, notes)) == len(notes):
            ffound = l
            break

    print "Case #%d: %s" % (t+1, ffound or "NO")
