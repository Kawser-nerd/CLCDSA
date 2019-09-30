abc_list = list(map(int, input().split()))
k = int(input())
ans = 0
for i in range(k):
    abc_list[abc_list.index(max(abc_list))] = max(abc_list) * 2
print(sum(abc_list))