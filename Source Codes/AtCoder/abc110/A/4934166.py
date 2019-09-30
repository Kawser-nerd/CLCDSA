abc = list(map(int, input().split()))
sorted_list = sorted(abc, reverse=True)
print(sorted_list[0] * 10 + sorted_list[1] + sorted_list[2])