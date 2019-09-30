N = int(input())
p_list = list(map(int, input().split()))

r = {}
for i in range(N):
    r[p_list[i]] = i + 1

a_list = []
b_list = []
for i in range(1, N + 1):
    a_list.append(30000 * i)
    b_list.append(30000 * (N - i) + r[i])

print(*a_list)
print(*b_list)