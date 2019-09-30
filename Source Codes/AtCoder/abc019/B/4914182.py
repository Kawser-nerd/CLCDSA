s = list(input())

ans = ''

i = 0
while i < len(s):
    j = i + 1
    while j < len(s):
        if s[j] != s[j-1]:
            break
        j += 1
    else:
        ans += s[i] + str(j - i)
        print(ans)
        exit()
    ans += s[i] + str(j - i)
    i = j