s = list(input())

ans = []
for x in ['A', 'B', 'C', 'D', 'E', 'F']:
    ans.append(str(s.count(x)))

print(' '.join(ans))