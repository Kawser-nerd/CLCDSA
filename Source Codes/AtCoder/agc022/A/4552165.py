import string

alphabet = string.ascii_lowercase

S = input()
count = list(map(lambda x: S.count(x), alphabet))

# add the alphaebts
for a in alphabet:
    if count[alphabet.index(a)] == 0:
        print(S + a)
        exit()

count = [0 for _ in range(len(alphabet))]
cand = ""

# change the alphabets
for i, s in enumerate(S[::-1]):
    cand += s
    if i == len(S) - 1:
        print(-1)
        exit()
    res = ""
    for a in cand:
        if ord(S[-(i + 2)]) < ord(a):
            if res and res < S[: len(S) - i - 2] + a:
                exit
            else:
                res = S[: len(S) - i - 2] + a
    if res:
        print(res)
        exit()