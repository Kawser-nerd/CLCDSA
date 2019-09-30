N, M, X = map(int, input().split())
lst = [0]*(N+1)
cost_idx = map(int, input().split())
for i in cost_idx:
    lst[i] = 1
left = sum(lst[:X+1])
right = sum(lst[X:])
print(min(left, right))