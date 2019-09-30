n = int(input())
cs = input().strip()
cd = {'1': 0, '2': 0, '3': 0, '4': 0}
for c in cs:
  cd[c] += 1

print(max(v for v in cd.values()), min(v for v in cd.values()))