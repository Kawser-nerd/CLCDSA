N, K = map(int, input().split())

rules = []
for i in range(N):
    a, b = map(int, input().split())
    rules.append((a, b))

rules = sorted(rules, key=lambda x: x[0])
for rule in rules:
    K -= rule[1]
    if K <= 0:
        print(rule[0])
        break