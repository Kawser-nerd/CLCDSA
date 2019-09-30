from collections import Counter

N = int(input())
w_list = [input() for _ in range(N)]

cnt = Counter(w_list).most_common(1)[0][1]
if cnt > 1:
    print('No')
else:
    for i in range(0,N - 1):
        if w_list[i][-1] != w_list[i + 1][0]:
            print('No')
            break
    else:
        print('Yes')