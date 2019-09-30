s = input()
ans = 0
memo = []
for i in range(1 << len(s) -1):
    tmp = s[0]
    for j in range(len(s)-1):
        if ((i >> j) & 1):
            tmp+="+"
        tmp += s[j+1]
    if tmp not in memo:
        ans+=eval(tmp)
        memo.append(tmp)
print(ans)