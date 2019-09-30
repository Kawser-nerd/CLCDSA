s = input()
x, y = map(int, input().split())
m = list(map(len, s.split('T')))
# ???????????
dp_x = {m[0]}
for i in m[2::2]:
    new_dp = set()
    for v in dp_x:
        new_dp |= {v + i, v - i}
    dp_x = new_dp

dp_y = {0}
for i in m[1::2]:
    new_dp = set()
    for v in dp_y:
        new_dp |= {v + i, v - i}
    dp_y = new_dp

print('Yes' if x in dp_x and y in dp_y else 'No')