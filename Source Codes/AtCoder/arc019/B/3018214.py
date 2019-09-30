def count_diff_ch(s):
    count = 0
    length = len(s)
    for i in range(0, length//2):
        if s[i] != s[length - i - 1]:
            count += 1
    return count


s = input()
c = count_diff_ch(s)
ans = len(s) * 25
parity = len(s) % 2
if c == 0:
    ans -= parity * 25
elif c == 1:
    ans -= 2
print(ans)