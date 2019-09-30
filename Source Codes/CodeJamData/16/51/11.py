#!/usr/bin/python3

def run():
    s = input().strip()
    stack = []
    res = 0
    for c in s:
        if len(stack) > 0 and stack[-1] == c:
            stack.pop()
            res += 10
        else:
            stack.append(c)
    res += len(stack) // 2 * 5
    return res


tc = int(input())
for i in range(tc):
    res = run()
    print("Case #%d: %s" % (i+1, res))
