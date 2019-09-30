d = int(raw_input())

def go(mp, cnt, digit, s, let):
    while mp[let] >= 1:
        for i in s:
            mp[i] -= 1
        cnt[digit] += 1

for i in range(1,d+1):
    print 'Case #' + str(i) + ':',
    cnt = [0] * 10
    mp = dict()
    for i in range(26):
        mp[chr(ord('A') + i)] = 0
    s = raw_input()
    for i in s:
        mp[i] += 1
    go(mp, cnt, 0, 'ZERO', 'Z')
    go(mp, cnt, 2, 'TWO', 'W')
    go(mp, cnt, 6, 'SIX', 'X')
    go(mp, cnt, 8, 'EIGHT', 'G')
    go(mp, cnt, 4, 'FOUR', 'U')
    go(mp, cnt, 1, 'ONE', 'O')
    go(mp, cnt, 7, 'SEVEN', 'S')
    go(mp, cnt, 5, 'FIVE', 'V')
    go(mp, cnt, 3, 'THREE', 'R')
    go(mp, cnt, 9, 'NINE', 'I')
    ans = ''
    for i in range(10):
        for j in range(cnt[i]):
            ans += str(i)
    print ans
