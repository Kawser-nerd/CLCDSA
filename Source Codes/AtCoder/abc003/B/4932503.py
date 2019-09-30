def main():
    atcoder = 'atcoder'
    cnt = 0
    s = input()
    t = input()
    for i in range(len(s)):
        if s[i] == '@' and t[i] in atcoder:
            cnt +=1
        if t[i] == '@' and s[i] in atcoder:
            cnt +=1
        if s[i] == t[i]:
            cnt +=1
    if cnt == len(s):
        return 'You can win'
    else:
        return 'You will lose'
        
print(main())