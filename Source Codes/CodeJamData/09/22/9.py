inp = open("d:\\incoming\\b-large.in")
outp = open("b-large.out", "w")


# copied from http://blog.bjrn.se/2008/04/lexicographic-permutations-using.html
# the page specifies "Use freely." so I can use it according to the rules, yes?
# I don't have C++ compilers on this laptop...
def next_permutation(seq, pred=cmp):
    """Like C++ std::next_permutation() but implemented as
    generator. Yields copies of seq."""

    def reverse(seq, start, end):
        # seq = seq[:start] + reversed(seq[start:end]) + \
        #       seq[end:]
        end -= 1
        if end <= start:
            return
        while True:
            seq[start], seq[end] = seq[end], seq[start]
            if start == end or start+1 == end:
                return
            start += 1
            end -= 1
    
    if not seq: return []

    try:
        seq[0]
    except TypeError:
        raise TypeError("seq must allow random access.")

    first = 0
    last = len(seq)
    seq = seq[:]

    # Yield input sequence as the STL version is often
    # used inside do {} while.    
    if last == 1: return []

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

                # Change to yield references to get rid of
                # (at worst) |seq|! copy operations.
                return seq[:]
            if next == first:
                return []
    return []

cases = int(inp.readline())
for cc in xrange(cases):
    n = list(inp.readline().strip())
    m = "".join(next_permutation(n))
    if m == "":
        n.sort()
        lz = 0
        while lz < len(n) and n[lz] == "0":
            lz += 1
        ret = str(n[lz]) + "".join(["0"] * (lz+1) + n[lz+1:])
    else:
        ret = "".join(m)
    
        
    print "Case #%d: %s" % (cc+1, ret)
    outp.write("Case #%d: %s\n" % (cc+1, ret))

outp.close()
