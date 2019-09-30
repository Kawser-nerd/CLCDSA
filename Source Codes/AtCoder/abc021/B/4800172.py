n = input()
org = list(map(int, input().split(' ')))
k = input()
arr = list(map(int, input().split(' ')))
t_arr = list(set(arr + org))

print('YES') if len(arr + org) == len(t_arr) else print('NO')