N = int(input())
txy = [input() for i in range(N)]
now_pos = [0, 0]
now_time = 0
fail_flag = False
for i in range(N):
    t, x, y = map(int, txy[i].split(' '))
    if (x+y) % 2 != t % 2:
        fail_flag = True
    distance = (abs(now_pos[0]-x) + abs(now_pos[1]-y))
    if distance > t:
        fail_flag = True
    if fail_flag:
        print('No')
        exit()
print('Yes')