N = int(input())
stacks = []
for _ in range(N):
    w = int(input())
    if len(stacks) == 0:
        stacks.append(w)
    else:
        for i, s in enumerate(stacks):
            if w <= s:
                stacks[i] = w
                break
        else:
            stacks.append(w)
        stacks = sorted(stacks)
print(len(stacks))