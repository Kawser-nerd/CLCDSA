# -*- coding: utf-8 -*-
N = int(input())
pairs = []
for i in range(N):
    tmp = input()
    pairs.append([int(a) for a in tmp.split()])

pos_and_vals = []
for i, (from_, to_) in enumerate(pairs):
    pos_and_vals.append(((i, 0), from_))
    pos_and_vals.append(((i, 1), to_))

pos_and_vals_sorted = sorted(pos_and_vals, key=(lambda x: x[1]))
pos_and_vals_sorted_toN = pos_and_vals_sorted[:N]

directions = [[False, False] for _ in range(N)]
for (i, direction), val in pos_and_vals_sorted_toN:
    directions[i][direction] = True

smallest_sum = sum([val for (i, direction), val in pos_and_vals_sorted_toN])
first_direction = pos_and_vals_sorted[0][0][1]
if all([direction == first_direction for (i, direction), val in pos_and_vals_sorted_toN]):
    # if all to or all from
    # let it go
    answer = smallest_sum
elif any([(not direction[0]) and (not direction[1]) for direction in directions]):
    # if x exists and x is unused, then let it go
    answer = smallest_sum
else:
    highest_inner = pos_and_vals_sorted[N-1]
    lowest_outer = pos_and_vals_sorted[N]
    if highest_inner[0][0] != lowest_outer[0][0]:
        # replace and make it unused
        answer = smallest_sum - highest_inner[1] + lowest_outer[1]
    elif all([direction == lowest_outer[0][1]
              for (i, direction), val in pos_and_vals_sorted_toN[:N-1]]):
        # if all except target is all the same direction, then let it go
        answer = smallest_sum - highest_inner[1] + lowest_outer[1]
    else:
        assert N >= 2
        # candidates are only two
        second_highest_inner = pos_and_vals_sorted[N-2]
        second_lowest_outer = pos_and_vals_sorted[N + 1]
        candidate_one = smallest_sum - second_highest_inner[1] + lowest_outer[1]
        candidate_two = smallest_sum - highest_inner[1] + second_lowest_outer[1]
        answer = min(candidate_one, candidate_two)

print(answer)