from collections import Counter

S = input()

S_counter = Counter(S)

pair, one = 0, 0
for m in S_counter.values():
    if m%2 == 1:
        m -= 1
        one += 1
    pair += m

if one == 0:
    print(pair)
else:
    # print(pair, one)
    print(pair//2//one*2+1)