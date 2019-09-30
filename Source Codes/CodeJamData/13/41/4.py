from heapq import *


# f = open('ticket.in'); rl = f.readline
rl = lambda: raw_input().strip()
cases = int(rl())
for cc in xrange(cases):
    n, m = map(int, rl().split())
    pairs = [map(int, rl().split()) for i in xrange(m)]

    def sigma(x):
        return (x * (x+1)) / 2

    def cost(start, end):
        assert 1 <= start <= end <= n
        diff = end - start
        return n * diff - sigma(diff)

    original = sum([cost(start, end) * cnt for start, end, cnt in pairs])

    ENTER, LEAVE = 0, 1

    # pairs of (start, end, -delta)
    events = []
    for start, end, cnt in pairs:
        heappush(events, (start, ENTER, end, cnt))

    # pairs of (-took_at, cnt)
    tickets = []

    discounted = 0

    while events:
        event = heappop(events)
        type = event[1]
        # print 'EVENT', event
        if type == ENTER:
            here, _, end, cnt = event

            heappush(events, (end, LEAVE, cnt))
            heappush(tickets, (-here, cnt))
            # print 'enter %d at %d' % (cnt, here)
        elif type == LEAVE:
            here, _, cnt = event

            # print 'leave %d at %d' % (cnt, here)

            while cnt > 0:
                took_at, ticket_cnt = heappop(tickets)
                took_at = -took_at

                effective_cnt = min(ticket_cnt, cnt)
                discounted += cost(took_at, here) * effective_cnt

                # print 'take %d tickets purchased at %d, paying %d each' % (
                #     effective_cnt,
                #     took_at,
                #     cost(took_at, here))

                cnt -= effective_cnt
                ticket_cnt -= effective_cnt

                if ticket_cnt > 0:
                    heappush(tickets, (-took_at, ticket_cnt))
        else:
            assert False
            
    print "Case #%d: %d" % (cc + 1, original - discounted)
            
