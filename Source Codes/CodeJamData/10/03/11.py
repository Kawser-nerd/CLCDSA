

class RideResult(object):
    def __init__(self, cash_gained, next_index):
        self.cash_gained = cash_gained
        self.next_index = next_index
    def __repr__(self):
        return "(+%s,->%s)" % (self.cash_gained, self.next_index)

def get_ride_result(groups, num_groups, start_index, people):
    index = start_index
    accepted_people = 0
    accepted_groups = 0
    while accepted_groups<num_groups:
        next_group_size = groups[index]
        if next_group_size > people:
            return RideResult(accepted_people, index)
        accepted_people += next_group_size
        accepted_groups += 1
        people -= next_group_size
        index = (index + 1) % num_groups
    return RideResult(accepted_people, index)

def multiply_ride_results(first_results, second_results=None):
    if second_results is None:
        second_results = first_results
    return [
        RideResult(
            first.cash_gained+second_results[first.next_index].cash_gained,
            second_results[first.next_index].next_index)
        for first in first_results]

def solve(runs_in_day,kar_size,num_groups,groups):
    people_in_a_full_cycle = sum(groups)
    groups_accepted = []
    #full_cycles_per_ride = kar_size // people_in_a_full_cycle
    #incremental_people_per_ride = kar_size % people_in_a_full_cycle
    results_after_n_rides = {}
    results_after_n_rides[1]=[
        get_ride_result(groups, num_groups, i, kar_size)
        for i in xrange(num_groups)]
    for x in xrange(1,30):
        n = 1<<x
        results_after_n_rides[n] = (
            multiply_ride_results(results_after_n_rides[n//2]))
    #for x in xrange(30):
    #    n = 1<<x
    #    #print n, results_after_n_rides[n]
    index = 0
    cash = 0
    for x in reversed(xrange(0,30)):
        n = 1<<x
        if runs_in_day >= n:
            #print "Do %s runs" % x
            #print "   gain %s cash" % results_after_n_rides[n][index].cash_gained
            #print "   goto %s" %  results_after_n_rides[n][index].next_index
            runs_in_day -= n
            cash += results_after_n_rides[n][index].cash_gained
            index = results_after_n_rides[n][index].next_index
    return cash

t = int(raw_input())
for case in xrange(t):
    r,k,n = [int(s) for s in raw_input().split()]
    gs = [int(s) for s in raw_input().split()]
    print "Case #%s: %s" % (case+1,solve(r,k,n,gs))
