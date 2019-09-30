def next_permutation(seq, pred=cmp):
    def reverse(seq, start, end):
        end -= 1
        if end <= start:
            return
        while True:
            seq[start], seq[end] = seq[end], seq[start]
            if start == end or start + 1 == end:
                return
            start += 1
            end -= 1
    first = 0
    last = len(seq)
    seq = seq[:]

    if last == 1:
        return None

    while True:
        next = last - 1

        while True:
            # Step 1.
            next1 = next
            next -= 1
            
            if pred(seq[next], seq[next1]) < 0:
                # Step 2.
                mid = last - 1
                while not (pred(seq[next], seq[mid]) < 0):
                    mid -= 1
                seq[next], seq[mid] = seq[mid], seq[next]
                
                # Step 3.
                reverse(seq, next1, last)

                return seq[:]
            if next == first:
                return  None


f = open('B-large.in')
T = int(f.readline().strip())
for t in range(T):
    print "Case #%s:" % (t+1,),
    n = list(f.readline().strip())
    np = next_permutation(n)
    if np is None:
        n.sort()
        first = [x for x in n if x > '0'][0]
        del n[n.index(first)]
        n = [first, '0'] + n
    else:
        n = np
    print ''.join(n)