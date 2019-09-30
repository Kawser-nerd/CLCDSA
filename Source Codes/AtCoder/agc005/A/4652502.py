s = input()
t = []
cnt = 0
for a in s:
    t.append(a)
    cnt += 1
    if cnt >= 2:
        if t[-2] == 'S' and t[-1] == 'T':
            cnt -= 2
            for i in range(2):
                t.pop(-1)
print(cnt)