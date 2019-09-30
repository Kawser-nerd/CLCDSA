# train has N seats 1 ... N
# each ticket has seat number
# i can promote ticket (decrease its number)
# given set of tickets, what's min number of rides given that i can promote tix?
# what's min number of tix that i have to promote?
# promoting one ticket counts as one promotion

# ok, let's think about first problem first
# if k people all have ticket 1 then we have to have k rides
# if k people have ticket 2 (and no other tickets) then we can have k/2 rides and promote half of the tickets to 1
# only makes sense for promotions to occur in cases where there are more tickets for seat i than seat i - 1

# ok we can think of min number of trains problem as follows:
# if k trains run, then at most k people with ticket 1 can ride; at most 2 k
# people with tickets 1-2 can ride; at most 3 k people with tickets 1-3 can
# ride, etc. so we can take cumulative sum and figure out what critical number is
# then greedily put people in spots

# oh crap, one person can hold multiple tickets....
# if 1 person holds k copies of ticket 2 then we still have to have k rides

# can we still take greedy approach?
# is min width just max number of tickets held by one person, max with above metric?

import collections

def iceil(a, b):
    assert b > 0
    if a == 0:
        return 0
    else:
        return (a - 1) / b + 1

def solve(n, tickets):
    # tickets = [(seat, holder)]
    holder_hist = collections.Counter(holder for (seat, holder) in tickets)
    seat_hist = collections.Counter(seat - 1 for (seat, holder) in tickets)
    max_holder = max(holder_hist.values())
    tix_width = 0
    tix_so_far = 0
    for i in xrange(n):
        tix_so_far += seat_hist[i]
        tix_width = max(tix_width, iceil(tix_so_far, i + 1))
    assert tix_so_far == len(tickets)
    width = max(max_holder, tix_width)
    promotions = 0
    for i in xrange(n):
        if seat_hist[i] > width:
            promotions += seat_hist[i] - width
    return (width, promotions)

if __name__ == '__main__':
    import sys
    fp = open(sys.argv[1])
    def readline():
        return fp.readline().strip()
    num_cases = int(readline())
    for i in xrange(num_cases):
        n, c, m = [int(x) for x in readline().split()]
        tickets = []
        for j in xrange(m):
            seat, holder = [int(x) for x in readline().split()]
            tickets.append((seat, holder))
        width, promotions = solve(n, tickets)
        print "Case #%d: %d %d" % (i + 1, width, promotions)
