if __name__ == '__main__':
    islands_count, demands_count = list(map(int, input().split()))
    demands = []
    break_count = 0

    for i in range(demands_count):
        demand = list(map(int, input().split()))
        demands.append(demand)

    demands.sort(key=lambda x: x[1])
    west_edge = 0

    for demand in demands:
        if demand[0] >= west_edge:
            break_count += 1
            west_edge = demand[1]

    print(break_count)