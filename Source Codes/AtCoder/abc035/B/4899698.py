s = list(input())
t = int(input())
c = [0, 0]
for s_ in s:
    if s_ == "L":
        c[0] += -1
    elif s_ == "R":
        c[0] += 1
    elif s_ == "U":
        c[1] += 1
    elif s_ == "D":
        c[1] += -1
ques = s.count("?")
ans = abs(c[0]) + abs(c[1])
if t == 1:
    ans += ques
else:
    for i in range(ques):
        if ans > 0:
            ans -= 1
        elif ans == 0:
            ans += 1
print(ans)