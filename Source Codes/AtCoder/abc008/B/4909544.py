n = int(input())

s = [input() for i in range(n)]

name = list(set(s))

count = [0]*len(name)

for i in range(len(s)):
    for k in range(len(name)):
        if s[i] == name[k]:
            count[k] += 1
            break

ans = 0
for i in range(len(count)):
    if count[i] > count[ans]:
        ans = i

print(name[ans])