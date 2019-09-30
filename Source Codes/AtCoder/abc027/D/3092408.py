S = input()
s_sum = [0]
# ???
for s in S:
    if s == '+':
        s_sum.append(s_sum[-1] + 1)
    elif s == '-':
        s_sum.append(s_sum[-1] - 1)
    else:
        s_sum.append(s_sum[-1])
total = sum(s_sum)
r_sum = []
for i, s in enumerate(S):
    if s == 'M':
        r_sum.append(total - s_sum[i + 1])
r_sum.sort()
print(sum(r_sum) - 2 * sum(r_sum[:len(r_sum) // 2]))