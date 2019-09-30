n = int(input())
n %= 30
s = [str(i+1) for i in range(6)]

for i in range(n):
    s[i % 5], s[i % 5 + 1] = s[i % 5 + 1], s[i % 5]

print(''.join(s))