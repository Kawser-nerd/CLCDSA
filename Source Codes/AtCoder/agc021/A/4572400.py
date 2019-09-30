S = input()
ans = sum(int(c) for c in S)
for i in range(1,len(S)):
    tmp = sum(int(c) for c in S[:i]) - 1 + 9*(len(S)-i)
    ans = max(ans, tmp)
print(ans)