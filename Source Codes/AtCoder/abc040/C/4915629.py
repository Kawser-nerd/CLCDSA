if __name__ == '__main__':
    scaffold_count = int(input())
    scaffold_list = list(map(int, input().split()))
    jump_costs = [0] * scaffold_count
    jump_costs[0] = 0
    jump_costs[1] = abs(scaffold_list[0] - scaffold_list[1])
    for i in range(2, scaffold_count):
        jump_costs[i] = min(jump_costs[i - 2] + abs(scaffold_list[i - 2] - scaffold_list[i]),
                            jump_costs[i - 1] + abs(scaffold_list[i - 1] - scaffold_list[i]))
    print(jump_costs[scaffold_count - 1])