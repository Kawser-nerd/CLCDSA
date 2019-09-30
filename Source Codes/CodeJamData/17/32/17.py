#!/usr/bin/python

import sys
import time
import itertools

DEBUG = False


def read_test_data():
    a_c, a_j = readline([int, int])
    ints = []
    for _ in range(a_c):
        ints.append(readline([int, int]) + [0])

    for _ in range(a_j):
        ints.append(readline([int, int]) + [1])

    return ints


def compute_test_result(test_data):
    variable_gaps = []
    owned_gaps = [], []
    time_spent = [0, 0]
    exchanges = 0
    # first find minimum number of exchanges, unbalanced
    ints = test_data
    ints.sort()

    for i in range(len(ints)):
        current, next = ints[i], ints[(i+1) % len(ints)]

        time_spent[current[2]] += current[1] - current[0]
        if current[2] == next[2]:
            owned_gaps[current[2]].append((next[0] - current[1]) % 1440)
        else:
            variable_gaps.append((next[0] - current[1]) % 1440)
            exchanges += 1

    # then resolve the gaps in the proper direction

    # 0 has an excess:
    if time_spent[0] + sum(owned_gaps[0]) > 720:
        excess = time_spent[0] + sum(owned_gaps[0]) - 720
        owned_gaps[0].sort()
        while excess > 0:
            excess -= owned_gaps[0].pop()
            exchanges += 2
    elif time_spent[1] + sum(owned_gaps[1]) > 720:
        excess = time_spent[1] + sum(owned_gaps[1]) - 720
        owned_gaps[1].sort()
        while excess > 0:
            excess -= owned_gaps[1].pop()
            exchanges += 2
    return exchanges


def main():
    T = int(sys.stdin.readline())
    for i in range(1, T + 1):
        test_data = read_test_data()

        if DEBUG:
            start_time = time.time()
            print "Case #{} INPUT: {}".format(i, test_data)
            print "Case #{}: {}".format(i, compute_test_result(test_data))
            elapsed = time.time() - start_time
            print "TIME: {:.2f}s".format(elapsed)
            print
        else:
            print "Case #{}: {}".format(i, compute_test_result(test_data))


def readline(types):
    objects = []
    type_index = 0

    for token in sys.stdin.readline().split():
        objects.append(types[type_index](token))

        if type_index + 1 < len(types):
            type_index += 1

    return objects


def split_list(raw_list, index):
    return raw_list[:index] + [raw_list[index:]]


def find_augmenting_path_bfs(capacities, source, sink):
    assert source != sink

    parents = [None] * len(capacities)
    flow = [None] * len(capacities)

    parents[source], flow[source] = -2, float("inf")

    queue = [source]
    while queue:
        node = queue.pop()

        if node == sink:
            # flow found!
            path = []

    return None

def interval_queue(intervals):
    """
    Takes in a list of closed interval tuples: (a, b, data) corresponds to [a, b], marked with data.
    For each event, yields a set of the currently active intervals.
    """

    START_FLAG = 0
    END_FLAG = 1

    interval_events = []
    for interval in intervals:
        interval_events.append((interval[0], START_FLAG, interval))
        interval_events.append((interval[1], END_FLAG, interval))
    interval_events.sort()

    active_intervals = []
    yield active_intervals

    for interval_event in interval_events:
        event_type = interval_event[1]
        assert event_type in [START_FLAG, END_FLAG]
        if event_type == START_FLAG:
            active_intervals.append(interval_event[2])
        else:
            active_intervals.remove(interval_event[2])

        yield active_intervals


def floyd_warshall(adjacency):
    """
    Input: adjacency is a square matrix, where float("inf") denotes no path exists.
    Modifies in place.
    """
    nodes = len(adjacency)
    assert len(adjacency[0]) == nodes

    for t in range(nodes):
        for u, v in itertools.product(range(nodes), repeat=2):
            new_dist = adjacency[u][t] + adjacency[t][v]
            if new_dist < adjacency[u][v]:
                adjacency[u][v] = new_dist

if __name__ == "__main__":
    main()
