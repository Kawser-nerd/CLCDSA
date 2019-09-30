s = input()
chars = set(s)
ans = len(s)

for c in chars:
    max_partial_char_length = max(len(_) for _ in s.split(c))
    ans = min(ans, max_partial_char_length)

print(ans)