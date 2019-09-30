S = input()
s = list(S)
s_len = len(S)

for _ in range(s_len):
    s.pop()
    if len(s) % 2 == 0 and s[:len(s) // 2] == s[len(s) // 2:]:
        ans = len(s)
        break
print(ans)