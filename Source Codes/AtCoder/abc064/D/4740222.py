from collections import deque
N = int(input())
S = input()
dq = deque()
ans = deque(list(S))
for s in S:
    if not dq:
        dq.append(s)
    else:
        if dq[-1] == "(" and s == ")":
            dq.pop()
        else:
            dq.append(s)
while dq:
    value = dq.popleft()
    if value == ")":
        ans.appendleft("(")
    elif value == "(":
        ans.append(")")
ans = "".join(ans)
print(ans)