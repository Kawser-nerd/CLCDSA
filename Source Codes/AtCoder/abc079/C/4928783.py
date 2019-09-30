from collections import deque
A,B,C,D = list(input())

dq = deque()
dq.append("")
while dq:
    op = dq.pop()
    if len(op) == 3:
        res = A + op[0] + B + op[1] + C + op[2] + D
        if eval(res) == 7:
            ans = res + "=7"
            print(ans)
            break
    else:
        dq.append(op+"+")
        dq.append(op+"-")