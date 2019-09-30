from collections import defaultdict

n = int(input())
s = input()
s1 = s[:n]
s2 = s[n:][::-1]
def makeDic(s):
    dic = defaultdict(int)
    for i in range(2 ** n):
        mask = 1
        c1 = ""
        c2 = ""
        for j in range(n):
            if i & mask:
                c1 += s[j]
            else:
                c2 += s[j]
            mask <<= 1
        dic[(c1, c2)] += 1
    return dic


dic1 = makeDic(s1)
dic2 = makeDic(s2)
ans = 0
for key in dic1:
    if key in dic2:
        ans += dic1[key] * dic2[key]
print(ans)