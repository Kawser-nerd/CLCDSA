N = int(input())
a = map(int, input().split())

color_set = set()
original_cnt = 0
red_flag = False
for val in a:
    if val >= 3200:
        original_cnt += 1
    else:
        if val >= 2800:
            red_flag = True
        color_set.add(int(val / 400))
if red_flag is True:
    print('{} {}'.format(len(color_set), len(color_set) + original_cnt))
else:
    if original_cnt > 0:
        print('{} {}'.format(len(color_set) + 1, len(color_set) + original_cnt))
    else:
        print('{} {}'.format(len(color_set), len(color_set)))