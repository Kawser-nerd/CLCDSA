#!/usr/bin/python

import sys

def getline():
    return sys.stdin.readline()[:-1]

def trace(*strs):
    return
    print >> sys.stderr, '..',
    for str in strs:
        print >> sys.stderr, str,
    print >> sys.stderr

def convert_time_to_minutes(time):
    (hh,mm) = time.split(':')
    assert int(hh) <= 23
    assert int(mm) <= 59
    return int(hh) * 60 + int(mm)

def analyze_events(events, turnaround_time):
    trace()
    events.sort()
    trace('sorted events:', events)
    # sort is such that if two events happen at the same time,
    # 'A+T' comes before 'D'.
    # i.e., we know about the ready train just as we need it to depart!

    n_trains_we_need_ready_at_start = 0
    n_trains_ready_currently = 0
    for event in events:
        trace(event)
        (mins, arr_dep, time) = event
        if arr_dep == 'A+T':
            trace('       A train becomes ready.')
            n_trains_ready_currently += 1
            trace('       Now we have', n_trains_ready_currently, 'ready.')
        elif arr_dep == 'D':
            trace('       We must use a train.')
            # We must use a train
            if n_trains_ready_currently > 0:
                # yay, we have a train ready
                trace('       Yay, we have one ready.')
                n_trains_ready_currently -= 1
                trace('       With that one gone, we now have',n_trains_ready_currently,'ready.')
            else:
                trace("       Dang, we don't have one ready. Oh, look, here's one in the overnight shed.")
                assert n_trains_ready_currently == 0
                # We need to add one at day-start
                n_trains_we_need_ready_at_start += 1
                trace("       We've pulled", n_trains_we_need_ready_at_start, "from the overnight shed so far.")
                # Add that one to the current number,
                # but then subtract one for the departure,
                # i.e. n_trains_ready_currently stays at 0

    trace("In total, we pulled",n_trains_we_need_ready_at_start,"from the overnight shed.")
    return n_trains_we_need_ready_at_start

n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    trace( 'Case #', case_num )

    turnaround_time = int(getline())
    trace( 'turnaround_time:', turnaround_time )

    (n_trips_a_to_b,n_trips_b_to_a) = map(int,getline().split())

    a_events = []
    b_events = []

    trace(n_trips_a_to_b, 'trips A->B:')
    for i in range(n_trips_a_to_b):
        (dep_time, arr_time) = getline().split()
        assert dep_time < arr_time
        trace(dep_time, arr_time)
        a_events.append( (convert_time_to_minutes(dep_time),                'D',  dep_time) )
        b_events.append( (convert_time_to_minutes(arr_time)+turnaround_time,'A+T',arr_time+'+t') )

    trace(n_trips_b_to_a, 'trips B->A:')
    for i in range(n_trips_b_to_a):
        (dep_time, arr_time) = getline().split()
        assert dep_time < arr_time
        trace(dep_time, arr_time)
        b_events.append( (convert_time_to_minutes(dep_time),                'D',   dep_time) )
        a_events.append( (convert_time_to_minutes(arr_time)+turnaround_time,'A+T', arr_time+'+t') )

    trace('a_events:', a_events)
    trace('b_events:', b_events)

    n_start_at_a = analyze_events(a_events, turnaround_time)
    n_start_at_b = analyze_events(b_events, turnaround_time)

    print 'Case #%d: %d %d' % (case_num, n_start_at_a, n_start_at_b)

assert sys.stdin.readline() == ''

# vim: sw=4 ts=4 expandtab
