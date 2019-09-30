import sys

#def find_path(keys_to_open, keys_in_chest, search_list):
#    while search_list != []:
#        chests_to_open, current_keys, path = search_list.pop()
#        if chests_to_open == []: return path
#        new_path_added = False
#        for chest in chests_to_open:
#            if current_keys[keys_to_open[chest]] > 0:
#                tmp_current_keys = list(current_keys)
#                tmp_current_keys[keys_to_open[chest]] -= 1
#                for key_num in keys_in_chest[chest]:
#                    tmp_current_keys[key_num] += 1
#                tmp_chests_to_open = list(chests_to_open)
#                tmp_chests_to_open.remove(chest)
#                search_list.append((tmp_chests_to_open, tmp_current_keys, path + [chest]))  
#    return []
# 4 with this one: 3 1 2 4 6 7 5 8 12 13 14 9 10 16 17 18 19 11 15 20 (before i messed it up)

def find_path(keys_to_open, keys_in_chest, search_list, num_chests):
    while search_list != []:
        chests_to_open, current_keys, path = search_list.pop()
        if chests_to_open == []: return path
        for chest in chests_to_open:
            if current_keys[keys_to_open[chest]] > 0:
                tmp_current_keys = list(current_keys)
                tmp_current_keys[keys_to_open[chest]] -= 1
                for key_num in keys_in_chest[chest]:
                    tmp_current_keys[key_num] += 1
                tmp_chests_to_open = list(chests_to_open)
                tmp_chests_to_open.remove(chest)
                if is_possible(keys_to_open, keys_in_chest, tmp_current_keys, tmp_chests_to_open):
                    search_list.append((tmp_chests_to_open, tmp_current_keys, path + [chest]))  
    return []

def is_possible(keys_to_open, keys_in_chest, curr_keys, chests_left_input):
    total_keys_required = [0] * 201
    total_keys_available = list(curr_keys)
    for chest in chests_left_input:
        total_keys_required[keys_to_open[chest]] += 1
        chest_keys_list = keys_in_chest[chest]
        for key_num in chest_keys_list:
            total_keys_available[key_num] += 1

    for ii in range(len(total_keys_required)):
        if total_keys_required[ii] > total_keys_available[ii]:
            return False

    chests_left = list(chests_left_input)
    keys_available = []
    for ii in range(len(curr_keys)):
        if curr_keys[ii] > 0: keys_available.append(ii)
    while (keys_available != [] and chests_left != []):
        next_key = keys_available.pop()
        ii = 0
        while (ii < len(chests_left)):
            poss_chest_to_open = chests_left[ii]
            if keys_to_open[poss_chest_to_open] == next_key: 
                chests_left.remove(poss_chest_to_open)
                keys_available += keys_in_chest[poss_chest_to_open]
            else: ii += 1
    if chests_left == []: return True
    else: return False

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    K, N = map(int, f.readline().strip().split())
    tmp_start_keys = map(int, f.readline().strip().split())
    keys_to_open = [0] # 0 is a placeholder so that the indices work better
    keys_in_chest = [[]] # also have a placeholder here
    
    for nn in range(N):
        data = map(int, f.readline().strip().split())
        keys_to_open.append(data[0])
        keys_in_chest.append(data[2:])

    start_keys = [0] * (201)
    for key_num in tmp_start_keys:
        start_keys[key_num] += 1
    search_list = [(range(N, 0, -1), start_keys, [])]

    possible = is_possible(keys_to_open, keys_in_chest, start_keys, range(1, N+1))
    if possible: path = find_path(keys_to_open, keys_in_chest, search_list, N)
 
    print "Case #%d:" % (t + 1), " ".join([str(elem) for elem in path]) if possible else "IMPOSSIBLE"
