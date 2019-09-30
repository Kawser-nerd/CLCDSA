N = int(input())

flag = [False] * 9
ans = 0

for _ in range(N):
    inputs = input()
    ans += inputs.count('x')
    for i, item in enumerate(inputs):
        if item == 'o' and flag[i]:
            continue
        elif item == 'o' and not flag[i]:
            flag[i] = True
        elif flag[i]:
            flag[i] = False
            ans += 1
else:
    ans += flag.count(True)
print(ans)