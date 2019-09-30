S = input()
n = len(S)
d = [str(chr(i+97)) for i in range(26)]
ans = float('inf')
for dd in d:
    s = S
    t = ''
    m = 0
    while True:
        if s.count(dd) == len(s):
            break
        for i in range(len(s)-1):
            if s[i] == dd or s[i+1] == dd:
                t = t + dd
            else:
                t = t + s[i]
        s = t
        t = ''
        m += 1
    ans = min(ans,m)
print(ans)