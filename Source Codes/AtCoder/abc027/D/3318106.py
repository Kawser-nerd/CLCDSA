S = input()
plus, minus = S.count("+"), S.count("-")
ans = []
append = ans.append
for c in S:
    if c == "M":
        append(plus-minus)
    elif c == "+":
        plus -= 1
    else:
        minus -= 1
ans.sort()
print(-sum(ans[:len(ans)//2])+sum(ans[len(ans)//2:]))