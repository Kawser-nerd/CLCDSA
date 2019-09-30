N = int(input())
words = [input() for _ in range(N)]

for i, w in enumerate(words):
    if i == 0:
        continue
    if words.count(w) > 1:
        print('No')
        break
    if w[0] != words[i - 1][-1]:
        print('No')
        break
else:
    print('Yes')