N = int(input())
s = input()
s = s[1:] + s[0]
ans = []
for i, j in [('S', 'S'), ('S', 'W'), ('W', 'S'), ('W', 'W')]:
    ans = [i, j]
    for si in s:
        if ans[-1] == 'S':
            if si == 'o':
                ans.append(ans[-2])
            else:
                ans.append('W' if ans[-2] == 'S' else 'S')
        else:
            if si == 'o':
                ans.append('W' if ans[-2] == 'S' else 'S')
            else:
                ans.append(ans[-2])
    if ans[:2] == ans[-2:]:
        print(''.join(ans[:-2]))
        break
else:
    print(-1)