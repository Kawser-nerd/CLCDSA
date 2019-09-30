N, R = map(int, input().split())
s = "."+input()

pos = len(s) - s[::-1].index(".") - 1
cost = max(0, pos-R)
while pos > 0:
    pos = max(0, pos-R)
    cost += 1
    while s[pos] != ".":
        pos -= 1

print(cost)