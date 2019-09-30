n = int(input())
s = input()
c = [0]
for i in range(n):
    if s[i] == '(':
        c.append(c[-1] + 1)
    else:
        c.append(c[-1] - 1)
print(max(0, -min(c)) * '(' + s + max(0, c[-1] - min(c)) * ')')