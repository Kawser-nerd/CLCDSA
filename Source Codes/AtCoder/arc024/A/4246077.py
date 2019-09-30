from collections import Counter

L, R = map(int, input().split())
inputs_l = Counter([int(i) for i in input().split()])
inputs_r = Counter([int(i) for i in input().split()])

print(sum([min(inputs_r[key], value) for key, value in inputs_l.items()]))