s = input()
if len(set(s)) == 1:
    print('0')
else:
    word_list = list(set(s))
    cnt = 10**5
    for word in word_list:
        t = s[:]
        for i in range(1, len(s)):
            tmp = ''
            for j in range(len(t)-1):
                if t[j] == word or t[j+1] == word:
                    tmp += word
                else:
                    tmp += t[j]
            if len(set(tmp)) == 1:
                cnt = min(cnt, i)
                break
            t = tmp[:]
    print(cnt)