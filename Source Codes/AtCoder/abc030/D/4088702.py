N, a = map(int, input().split())
K = int(input())
a -= 1
B = list(map(lambda x: int(x) - 1, input().split()))

checked_list = [a]
checked_set = {a}
while True:
    next_index = B[checked_list[-1]]
    if next_index in checked_set:
        cycle = checked_list[checked_list.index(next_index):]
        break
    else:
        K -= 1
        checked_list.append(next_index)
        checked_set.add(next_index)

    if K == 0:
        print(next_index + 1)
        exit()

cycle_length = len(cycle)
ans = cycle[(K - 1) % cycle_length]
print(ans + 1)