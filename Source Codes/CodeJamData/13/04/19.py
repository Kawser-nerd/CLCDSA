import copy

f_in = open('D-small-attempt2.in', 'r')
f_out = open('D-small-attempt2.out', 'w')

num_cases = int(f_in.readline().strip())

def find_solution(key_list, chest_list, partial_solution):
    for bad_chest in chest_list:
        if (not bad_chest['lock'] in key_list) and (bad_chest['lock'] in bad_chest['keys_inside']):
            found_key = False
            for chest in chest_list:
                if chest != bad_chest and bad_chest['lock'] in chest['keys_inside']:
                    found_key = True
                    break
            if not found_key:
                return []
    
    for chest in chest_list:
        if chest['lock'] in key_list:
            new_key_list = copy.copy(key_list)
            new_key_list.remove(chest['lock'])
            new_key_list.extend(chest['keys_inside'])
            new_chest_list = copy.copy(chest_list)
            new_chest_list.remove(chest)
            if len(new_chest_list) == 0:
                return [chest['number']]
            new_solution = find_solution(new_key_list, new_chest_list, partial_solution + [chest['number']])
            if len(new_solution) > 0:
                new_solution.insert(0, chest['number'])
                return new_solution
    
    return []
            

for idx_case in range(num_cases):
    K_N_list = f_in.readline().strip().split()
    K = int(K_N_list[0])
    N = int(K_N_list[1])
    
    key_list = [int(s) for s in f_in.readline().strip().split()]
    total_key_list = copy.copy(key_list)
    lock_list = []
    chest_list = []
    for i in range(N):
        chest_data = [int(s) for s in f_in.readline().strip().split()]
        chest_list.append({'number': i + 1, 'lock': chest_data[0], 'keys_inside': chest_data[2:]})
        lock_list.append(chest_data[0])
        total_key_list.extend(chest_data[2:])
    
    feasible = True
    for chest in chest_list:
        if not chest['lock'] in total_key_list:
            feasible = False
            break
        total_key_list.remove(chest['lock'])
    
    if feasible:
        solution = find_solution(key_list, chest_list, [])
    else:
        solution = []
    
    if len(solution) == N:
        f_out.write('Case #{}: {}\n'.format(idx_case+1, ' '.join([str(i) for i in solution])))
    else:
        f_out.write('Case #{}: IMPOSSIBLE\n'.format(idx_case+1))

f_in.close()
f_out.close()