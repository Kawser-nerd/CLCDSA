from collections import deque

def comb(s):
    p = deque([('','')])

    for i in range(len(s)):
        for j in range(2**i):
            e = p.pop()
            p.appendleft((e[0]+s[i],e[1]))
            p.appendleft((e[0],e[1]+s[i]))
    return p

n = int(input())
s = input()

sl = s[0:n]
sr = s[n:2*n][::-1]
keys1 = [c[0]+'-'+c[1] for c in comb(sl)]
keys2 = [c[0]+'-'+c[1] for c in comb(sr)]

dict = {}
for key1 in keys1:
    if key1 in dict:
        dict[key1] += 1
    else:
        dict[key1] = 1
cnt = 0
for key2 in keys2:
    if key2 in dict:
        cnt += dict[key2]

print(cnt)