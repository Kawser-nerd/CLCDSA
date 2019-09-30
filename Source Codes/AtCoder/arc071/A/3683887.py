n = int(input())
d = {}
for i in range(26):
    d[chr(i+97)] = []

for i in range(n):
    s = input()
    char_set = set(list(s))
    for c in char_set:
        d[c].append(s.count(c))

ans = ""
for i in range(26):
    c = chr(i+97)
    if len(d[c]) == n:
        ans += c*min(d[c])
print(ans)