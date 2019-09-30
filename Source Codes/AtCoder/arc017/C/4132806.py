import collections

N, X = map(int, input().split())
w = [int(input()) for i in range(N)]


a = N // 2
b = N - a
former = []
latter = []

for i in range(2**a):
    former.append(sum([w[j] * (i >> j & 1) for j in range(a)]))

for i in range(2**b):
    latter.append(sum([w[j+a] * (i >> j & 1) for j in range(b)]))

former_dict = collections.Counter(former)
latter_dict = collections.Counter(latter)
keys_1 = former_dict.keys()
keys_2 = latter_dict.keys()

ans = 0
for key in keys_1:
    if key < X:
        if X - key in keys_2:
            ans += former_dict[key] * latter_dict[X-key]
    elif key == X:
        ans += former_dict[X]

print(ans)