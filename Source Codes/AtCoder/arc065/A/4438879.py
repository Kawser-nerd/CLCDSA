from collections import deque

def solve(s):
    stack = deque()
    stack.append(s)
    while len(stack) > 0:
        top = stack.pop()
        if top == '':
            return 'YES'

        if top[:5] == 'dream':
            if top[5:7] == 'er':
                stack.append(top[7:])
            stack.append(top[5:])
        elif top[:5] == 'erase':
            if len(top) > 5 and top[5] == 'r':
                stack.append(top[6:])
            else:
                stack.append(top[5:])
    return 'NO'

print(solve(input()))