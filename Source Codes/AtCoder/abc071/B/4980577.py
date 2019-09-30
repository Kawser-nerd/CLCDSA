from collections import defaultdict
import string

S = input()

letters = defaultdict(lambda: False)
for s in S:
    letters[s] = True

ans = 'None'
for l in string.ascii_lowercase:
    if letters[l] == False:
        ans = l
        break
print(ans)