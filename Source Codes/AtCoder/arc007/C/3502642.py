S = input()
a = [sum(2**i for i, v in enumerate(S) if v == "o")]
goal = 2**len(S)-1
for i in range(len(S)-1):
    a.append(a[-1] % 2*(2**(len(S)-1)) + (a[-1] >> 1))
ans = [10]


def rec(n, count):
    if n == goal:
        ans[0] = min(ans[0], count)
        return
    for bit in a[count:]:
        if n | bit != n:
            rec(n | bit, count+1)


rec(a[0], 1)
print(ans[0])