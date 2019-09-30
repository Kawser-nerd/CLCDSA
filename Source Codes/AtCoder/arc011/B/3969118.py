def b_mnemonics(N, W):
    # ???????????????????????
    words = W.replace('.', '').lower().split()

    translation_dict = {'b': '1',
                        'c': '1',
                        'd': '2',
                        'w': '2',
                        't': '3',
                        'j': '3',
                        'f': '4',
                        'q': '4',
                        'l': '5',
                        'v': '5',
                        's': '6',
                        'x': '6',
                        'p': '7',
                        'm': '7',
                        'h': '8',
                        'k': '8',
                        'n': '9',
                        'g': '9',
                        'z': '0',
                        'r': '0', }
    ans = []
    for w in words:
        tmp = ''
        for c in w:
            if c not in translation_dict:
                continue
            tmp += translation_dict[c]
        if tmp:
            ans.append(tmp)  # ???????????????????
    return ' '.join(ans)

N = int(input())
W = input()
print(b_mnemonics(N, W))