s = input()
k = int(input())

a = sorted(set(s))[:5]
for num in range(2,6):
  if len(s) >= num:
    b = sorted(set([s[i:i+num] for i in range(len(s)-num+1)]))[:5]
    a.extend(b)
  else:
    break

print(sorted(a)[k-1])