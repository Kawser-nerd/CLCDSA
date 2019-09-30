n = int(input())
s = list(input())
t = list(input())
alp = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
flag = [True for i in range(30)]
key = [i for i in range(30)]
group = [[i] for i in range(30)]
dic = {}
ans = 1
for i in range(n):
    if s[i] in alp and t[i] in alp:
        a = alp.index(s[i])
        b = alp.index(t[i])
        if key[a] != key[b]:
            v = key[b]
            group[key[a]] = group[key[a]]+group[key[b]]
            for j in group[v]:
                key[j] = key[a]
            group[v] = []
for i in range(30):
    dic[i] = 1
for i in range(n)[::-1]:
    if s[i] not in alp and t[i] in alp:
        dic[key[alp.index(t[i])]] = 1
        flag[key[alp.index(t[i])]] = False
    if s[i] in alp and t[i] not in alp:
        dic[key[alp.index(s[i])]] = 1
        flag[key[alp.index(s[i])]] = False
    if s[i] in alp and t[i] in alp:
        if i == 0:
            if flag[key[alp.index(s[i])]]:
                dic[key[alp.index(s[i])]] = 9
        else:
            if flag[key[alp.index(s[i])]]:
                dic[key[alp.index(s[i])]] = 10
for i in dic.values():
    ans *= i
print(ans)