
def solve_case(case_num):
    M, F, N = [int(x) for x in raw_input().strip().split()]
    temp_foods = []
    for i in xrange(N):
        p, s = [int(x) for x in raw_input().strip().split()]
        temp_foods.append((s, p))
    temp_foods.sort()
    
    foods = []
    for s, p in temp_foods:
        if foods and s + 1 == foods[-1][0]:
            continue
        while foods and foods[-1][1] >= p:
            foods = foods[:-1]
        foods.append((s + 1, p))

    for i in xrange(len(foods) - 1):
        s, p = foods[i]
        assert s < foods[i + 1][0] and p < foods[i + 1][1]

#    print 'foods', foods
    
    cum_cost = [F]
    for i in xrange(len(foods)):
        num_days = foods[i][0] - (foods[i - 1][0] if i > 0 else 0)
        cum_cost.append(cum_cost[-1] + num_days * foods[i][1])

#    print zip([0] + [x for x, y in foods], cum_cost)

    def get_days(num_deliv, cash):
#        print 'getting', num_deliv, cash
        if cum_cost[0] * num_deliv > cash or num_deliv <= 0:
            return 0
        days = 0
        for i in xrange(len(foods) + 1):
            if cash < cum_cost[i] * num_deliv:
                assert i > 0
                return days + ((cash - cum_cost[i - 1] * num_deliv) 
                               / foods[i - 1][1])
            if i > 0:
                days = foods[i - 1][0] * num_deliv
        return days

    best_deal = (0, F) # (ix, cost)
    for i in xrange(1, len(foods) + 1):
        ix, cost = best_deal
        days = (foods[ix - 1][0] if ix > 0 else 0)
        if cum_cost[i] * days < foods[i - 1][0] * cost:
            best_deal = (i, cum_cost[i])

    assert best_deal[0] > 0

    best_cost = best_deal[1]
#    print 'best deal', foods[best_deal[0] - 1][0], best_cost

    answers = [get_days(M / best_cost + i, M) for i in [-2, -1, 0, 1, 2]]
#    print answers
    answer = max(answers)
    print ('Case #%d: %d' % (case_num, answer))
    
T = int(raw_input().strip())
for i in xrange(T):
    solve_case(i + 1)
