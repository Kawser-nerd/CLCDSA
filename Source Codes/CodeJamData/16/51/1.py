t = int(input())

def solve(s):
    assert (len(s) % 2 == 0)
    k = len(s) // 2
    stack = []
    score = 0
    for i in range(len(s)):
        if (stack == [] or s[i] != stack[-1]) and k > 0:
            k -= 1
            stack.append(s[i])
        else:
            e = stack.pop()
            if e == s[i]:
                score += 10
            else:
                score += 5
    return score

for i in range(t):
    print("Case #%d:" % (i + 1), end = " ")
    s = input().strip()
    print(solve(s))
