s = input()
master = 753
ans = []

for i in range(len(s)):
    x = int(s[i:i+3])
    calc = abs(master - x)
    ans.append(calc)

print(min(ans))