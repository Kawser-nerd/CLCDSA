from bisect import bisect_left

CHARACTERs = 'abcdefghijklmnopqrstuvwxyz'

As = input()
lenA = len(As)

posChars = dict([(ch, [lenA]) for ch in CHARACTERs])
dp = [0] * lenA + [1, 0]
for i in reversed(range(lenA)):
    posChars[As[i]].append(i)
    dp[i] = min([dp[posChars[ch][-1] + 1] for ch in CHARACTERs]) + 1

for ch in CHARACTERs:
    posChars[ch] = posChars[ch][::-1]

ans = []
i = 0
for k in reversed(range(dp[0])):
    for ch in CHARACTERs:
        pos = posChars[ch][bisect_left(posChars[ch], i)]
        if dp[pos + 1] == k:
            ans.append(ch)
            i = pos + 1
            break

print(''.join(ans))