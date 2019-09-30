import heapq
from collections import defaultdict
import sys

f = open("input", "r")

test_cases = int(f.readline().strip())

def solve(level_count, a, b):        
    aval_to_indices = defaultdict(set)
    bval_to_indices = defaultdict(set)

    for i in range(level_count):
        aval_to_indices[a[i]].add(i)
        bval_to_indices[b[i]].add(i)

    previous_stars            = -1
    stars                     = 0    
    stars_for_level           = [0 for i in range(level_count)]
    available_two_stars       = set()
    finishable_part_completes = set()
    available_one_stars       = []    
    play_count                = 0
    
    while stars != 2 * level_count:
        while previous_stars != stars:
            previous_stars += 1
            
            # add new choices available upon reaching this number of stars
            for i in bval_to_indices[previous_stars]:
                if stars_for_level[i] == 0:
                    available_two_stars.add(i)
                else:
                    finishable_part_completes.add(i)
            for i in aval_to_indices[previous_stars]:                
                # will also check later when we pop this that it hasn't
                # already been done. Use -b[i] as the priority as we want
                # to pick the one with highest b[i] later
                heapq.heappush(available_one_stars, (-b[i],i))
                
        # if any untried 2-star levels available
        if available_two_stars:
            two_star_index = available_two_stars.pop()
            stars += 2
            assert stars_for_level[two_star_index] == 0
            stars_for_level[two_star_index] = 2
            #print >> sys.stderr, "2-star. i: {}, a: {}, b: {}".format(
            #             two_star_index, a[two_star_index], b[two_star_index])
            
        elif finishable_part_completes:
            part_complete_index = finishable_part_completes.pop()
            stars += 1
            assert stars_for_level[part_complete_index] == 1
            stars_for_level[part_complete_index] = 2
            #print >> sys.stderr, "complete. i: {}, a: {}, b: {}".format(
            #       part_complete_index, a[part_complete_index],
            #       b[part_complete_index])        
        else:
            found = False
            while available_one_stars:
                one_star_index = heapq.heappop(available_one_stars)[1]
                if stars_for_level[one_star_index] != 0:
                    assert stars_for_level[one_star_index] == 2
                else:
                    found = True
                    stars += 1
                    assert stars_for_level[one_star_index] == 0
                    stars_for_level[one_star_index] = 1
                    #print >> sys.stderr, "1-star. i: {}, a: {}, b: {}".format(
                    #      one_star_index, a[one_star_index], b[one_star_index])
                    break
        
            if not found:
                return None # not solvable
        
        play_count += 1
        
    return play_count # solvable
    
    
        
for test_case in range(test_cases):
    level_count = int(f.readline().strip()) # n
    a, b = [[0 for i in range(level_count)] for j in range(2)]

    for i in range(level_count):
        a[i], b[i] = (int(s) for s in f.readline().strip().split(" ")) 
    
    min_times = solve(level_count, a, b)
    if min_times is None:
        print "Case #{}: Too Bad".format(test_case + 1)
    else:
        print "Case #{}: {}".format(test_case + 1, min_times)

