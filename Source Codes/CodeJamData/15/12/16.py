# Python 2

def count(barber, duration):
    return duration / barber + 1

def cuts_at(barber, time):
    return time % barber == 0

def binary_search(high_enough_pred, lower, upper):
    lower -= 1
    upper += 1
    while upper - lower > 1:
        mid = (lower + upper) / 2
        if (high_enough_pred(mid)):
            upper = mid
        else:
            lower = mid
    return upper

def how_many_haircuts(time):
    return sum(count(barber, time) for barber in barbers)

def did_I_get_a_haircut(time):
    return how_many_haircuts(time) >= n

def solve():
    upper = n * 100000 # binary search is log(n), so who cares if this is huge :)
    time = binary_search(did_I_get_a_haircut, 0, upper)
    people_at_same_time_as_me = n - how_many_haircuts(time - 1)
    barbers_cutting_now = [ i for i in xrange(len(barbers)) if cuts_at(barbers[i], time) ]
    my_barber = barbers_cutting_now[people_at_same_time_as_me - 1] + 1
    return my_barber

def input_ints():
    return map(int, raw_input().split())

def run():
    global n
    global barbers
    ts = input()
    for ti in xrange(ts):
        _, n = input_ints()
        barbers = input_ints()
        print "Case #%d: %d" % (ti + 1, solve())


if __name__ == "__main__":
    run()
