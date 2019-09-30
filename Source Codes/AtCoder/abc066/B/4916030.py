s = list(input())
for i in range(len(s)):
    del s[-1]
    s = "".join(s)
    if s[0:len(s)//2]*2 == s:
        print(len(s))
        break
    s = list(s)