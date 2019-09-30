T = int(input())
for i in range(T):
    s = input() + '+'
    ans = 0
    for j in range(len(s)-1):
        if s[j] != s[j+1]: ans += 1
    print("Case #%d: %d" % (i+1, ans))
