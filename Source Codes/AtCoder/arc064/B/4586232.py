s = input()
players = ['First', 'Second']

last = 1 if s[0] == s[-1] else 0
cnt = (len(s) - 2 + 1 + last) % 2
ans = players[cnt]

print(ans)