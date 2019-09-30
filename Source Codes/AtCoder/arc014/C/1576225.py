from collections import Counter

N = int(input())
S = input()
counter = Counter(S)

ans = 0
ans += counter['R']%2
ans += counter['G']%2
ans += counter['B']%2
print(ans)