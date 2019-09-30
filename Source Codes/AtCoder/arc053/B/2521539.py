S = list(map(lambda x: ord(x) - ord('a'), list(input())))
c = [0] * 26
for s in S:
    c[s] += 1

pair = 0
odd = 0
for n in c:
    if n%2 == 1:
        odd += 1
    pair += n//2
if odd == 0:
    print(len(S))
else:
    print(pair//odd*2+1)